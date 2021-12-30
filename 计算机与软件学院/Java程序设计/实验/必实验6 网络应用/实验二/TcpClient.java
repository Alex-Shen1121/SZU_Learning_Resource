package 实验二;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class TcpClient implements Runnable{
    Socket socket;
    int port;
    String Ip;


    public TcpClient(int port, String Ip) {
        this.port = port;
        this.Ip = Ip;
        new Thread(this).start();
    }

    @Override
    public void run() {
        int len=0;
        String result=null;
        try {
            InputStream is = socket.getInputStream();
            byte []receiveResult=new byte[1024];
            while((len=is.read(receiveResult))!=-1){
                result=new String(receiveResult,0,len);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
