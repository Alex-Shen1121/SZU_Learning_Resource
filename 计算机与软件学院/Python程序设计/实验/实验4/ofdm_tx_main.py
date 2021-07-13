from gnuradio import gr
from gnuradio import eng_notation
from gnuradio.eng_option import eng_option
from gnuradio import digital
from optparse import OptionParser

from uhd_interface import uhd_transmitter
import transmit_path

import time
import sys
import struct
import random


class my_top_block(gr.top_block):
    def __init__(self, options):
        gr.top_block.__init__(self)
        if options.freq is not None:
            self.d_tx_enable = True
            u = uhd_transmitter(options.tx_args,
                                options.bandwidth,
                                options.tx_freq, options.tx_gain,
                                options.spec, options.antenna,
                                options.verbose, options.external)
        elif options.outfile is not None:
            self.d_tx_enable = False
            u = gr.file_sink(gr.sizeof_gr_complex, options.outfile)
        else:
            raise SystemExit("--freq or --outfile must be specified\n")

        tx = transmit_path.ofdm_transmit_path(options)
        self.connect(tx, u)

        self.tx = tx
        self.u = u

    def send_pkt(self, payload='', time=None, eof=False, msgq_tx_enable=False):
        if eof and not msgq_tx_enable:
            self.tx.send_eof()
        elif eof and msgq_tx_enable:
            self.tx.send_eof2()

        if self.d_tx_enable:
            if msgq_tx_enable:
                self.tx.send_samples(payload, time)
            else:
                self.tx.send_pkt(payload, time)

    def add_options(normal, expert):

        normal.add_option("", "--outfile", type="string",
                          help="select output file to modulate to")
        normal.add_option("-N", "--numpkts", type="eng_float", default=0,
                          help="set number of packets to transmit [default=%default]")
        normal.add_option("", "--pause", type="eng_float", default=0.005,
                          help="inter-burst pause [s]")
        normal.add_option("-W", "--bandwidth", type="eng_float",
                          default=1e6,
                          help="set symbol bandwidth [default=%default]")
        expert.add_option("", "--time", action="store_true", default=False,
                          help="set timed tx mode [RawOFDM]")
        uhd_transmitter.add_options(normal)
        transmit_path.ofdm_transmit_path.add_options(normal, expert)

    add_options = staticmethod(add_options)


class MAC_TIMER:
    def __init__(self, start, GAP):
        self.pause = GAP
        self.time = start
        print "%f %f \n" % (start, self.time)
        self.tSlot = 9 * 0.000001
        self.tPkt = 260 * 4 * 0.000001
        self.tDIFS = 34 * 0.000001
        self.cnt = 0

    def get_next_txtime(self):
        self.cnt += 1
        if self.cnt > 1:
            t = random.randint(1, 32)
            self.pause = self.tPkt + self.tDIFS + t*self.tSlot
        self.time = self.time + self.pause
        return [self.time, self.pause]


def main():
    global f
    f = open('p2p_start_time.dat', 'w')

    def string_to_hex_list(s):
        return map(lambda x: hex(ord(x)), s)

    def example_tx_samples(tb, options):
        MAX_READ_BYTES = 1000000000
        file_object = open(options.data_file)
        rawdata = file_object.read(MAX_READ_BYTES)
        print "Length of payload = ", len(rawdata), " | MAX_READ = ", MAX_READ_BYTES

        num_floats = len(rawdata)/4
        txdata = rawdata
        file_object.close()

        start = time.time()
        if options.time:
            usrp_time, frac = tb.u.get_usrp_time()
            print "USRP Time: ", usrp_time+frac, frac
            startTime = usrp_time
        GAP = options.pause
        framebytes = tb.tx.framebytes
        numpkts = 10000 if options.numpkts == 0 else abs(int(options.numpkts))
        start = [0.0 for x in range(numpkts+1)]

        pktno = 1
        while pktno <= numpkts:
            if options.time:
                tx_ts = startTime+pktno*GAP
                pause_ts = GAP
                start[pktno] = tx_ts
                tb.send_pkt(txdata, tx_ts, eof=False, msgq_tx_enable=True)
                print "Send pkt# %d time:%f ..." % (pktno, startTime+pktno*GAP)
                time.sleep(0.8*pause_ts)
            else:
                tb.send_pkt(txdata, eof=False, msgq_tx_enable=True)
                print "Send pkt# %d" % (pktno)
                start[pktno] = time.time()
                if (options.pause > 0.0):
                    sys.stdout.flush()
                    time.sleep(options.pause*0.95)

            log = "%d %.6f \n" % (pktno, start[pktno])
            f.write(log)
            pktno = pktno + 1
            sys.stdout.write('.')

        tb.send_pkt(eof=True, msgq_tx_enable=True)
        elapsed = start[numpkts] - start[1]
        print "Sent %d packets of %d symbols in %.2f seconds" % (pktno-1, options.size, elapsed)
        print pktno*options.size / elapsed

    def example_tx_bits(tb, options):
        start = time.time()
        if options.time:
            usrp_time, frac = tb.u.get_usrp_time()
            print "USRP Time: ", usrp_time+frac
            startTime = usrp_time
        GAP = options.pause
        framebytes = tb.tx.framebytes
        numpkts = 10000 if options.numpkts == 0 else abs(int(options.numpkts))
        start = [0.0 for x in range(numpkts+1)]
        pktno = 1
        while pktno <= numpkts:
            pkt_type = struct.pack('!B', ord('B'))
            payload = pkt_type + \
                struct.pack('!H', pktno) + struct.pack('!H', 0)
            random.seed()
            for i in range(framebytes - len(payload) - 4):
                r = random.randint(0, 255)
                payload += struct.pack('!B', r)
            payload = digital.crc.gen_and_append_crc32(payload)

            if options.time:
                tb.send_pkt(payload, startTime+pktno*GAP)
                print "Send pkt# %d time:%f ..." % (pktno, startTime+pktno*GAP)
                start[pktno] = startTime+pktno*GAP
                time.sleep(GAP*0.8)
            else:
                tb.send_pkt(payload)
                print "Send pkt# %d ..." % (pktno)
                start[pktno] = time.time()
                if (options.pause > 0.0):
                    sys.stdout.flush()
                    time.sleep(options.pause*0.95)
                log = "%d %.6f \n" % (pktno, start[pktno])
                f.write(log)
                pktno = pktno + 1
                sys.stdout.write('.')

        tb.send_pkt(eof=True)
        elapsed = start[numpkts] - start[1]
        print "Sent %d packets of %d symbols in %.2f seconds" % (pktno-1, options.size, elapsed)
        if elapsed != 0:
            print pktno*options.size / elapsed

    parser = OptionParser(option_class=eng_option, conflict_handler="resolve")
    expert_grp = parser.add_option_group("Expert")

    my_top_block.add_options(parser, expert_grp)

    (options, args) = parser.parse_args()
    options.mode = None

    tb = my_top_block(options)

    r = gr.enable_realtime_scheduling()
    if r != gr.RT_OK:
        print "Warning: failed to enable realtime scheduling"

    tb.start()

    if options.data_file:
        example_tx_samples(tb, options)
    else:
        example_tx_bits(tb, options)
    print "Wait flowgraph to stop ..."
    tb.wait()


if __name__ == '__main__':
    try:
        main()
        f.close()
    except KeyboardInterrupt:
        f.close()
        pass
