package 实验一;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UdpSend implements Runnable{
    private DatagramSocket socket;
    //读取用户输入的bufferReader
    private BufferedReader br;
    //接收端的IP
    private InetAddress receiveAd;
    //接收端的端口
    private int receivePort;

    public UdpSend( InetAddress receiveAd, int receivePort) throws Exception {
        //成员变量的初始化
        this.socket = new DatagramSocket();
        this.br = new BufferedReader(new InputStreamReader(System.in));
        this.receiveAd = receiveAd;
        this.receivePort = receivePort;
    }
    @Override
    public void run() {
        while(true) {
            try{
                //读入用户输入的语句
                String msg = br.readLine();
                DatagramPacket packet = new DatagramPacket(msg.getBytes(), msg.getBytes().length,receiveAd , receivePort);
                //将输入语句发送给接收端
                socket.send(packet);
                //输入886结束发送数据
                if(msg.equals("886")){break;}

            }
            catch (Exception e){
               e.printStackTrace();
            }
        }
        socket.close();
    }
}