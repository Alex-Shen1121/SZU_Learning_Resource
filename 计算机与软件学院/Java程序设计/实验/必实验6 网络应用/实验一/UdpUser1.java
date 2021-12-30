package 实验一;

import java.net.InetAddress;

public class UdpUser1 {
    public static void main(String[] args) throws Exception{
        new Thread(new UdpReceive("User2",6666)).start();
        new Thread(new UdpSend(InetAddress.getByName("localhost"),9999)).start();
    }
}
