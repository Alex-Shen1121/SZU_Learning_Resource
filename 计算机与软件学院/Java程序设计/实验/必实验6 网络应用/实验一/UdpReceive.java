package 实验一;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class UdpReceive implements Runnable{
    private DatagramSocket socket;
    //接受数据的端口
    private int port;
    //发送者的名字
    private String senderName;
    public UdpReceive(String senderName,int port) throws SocketException {
        //成员变量初始化
        this.port = port;
        this.senderName=senderName;
        socket=new DatagramSocket(port);
    }
    @Override
    public void run() {
        while (true) {
            //接收数据
            byte[] receiveData = new byte[1024];
            DatagramPacket packet = new DatagramPacket(receiveData, 0, 1024);
            try {
                socket.receive(packet);
            } catch (IOException e) {
                e.printStackTrace();
            }
            String s = null;
            try {
                //将byte转为String
                s = new String(receiveData);
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println(senderName+":"+s);
            if (s.equals("bye")) break;
        }
        socket.close();
    }
}
