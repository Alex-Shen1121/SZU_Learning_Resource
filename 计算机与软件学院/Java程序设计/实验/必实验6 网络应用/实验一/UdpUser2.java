package 实验一;

import java.net.InetAddress;

public class UdpUser2 {
    public static void main(String[] args) throws Exception{
        new Thread(new UdpReceive("User1",9999)).start();
        new Thread(new UdpSend(InetAddress.getByName("localhost"),6666)).start();
    }
}
