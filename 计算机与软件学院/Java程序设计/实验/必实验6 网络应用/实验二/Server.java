package 实验二;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;

public class Server {
    private int port;//开发连接的端口
    private ServerSocket serverSocket;
    private HashMap<String, String> dictionary = new HashMap<>();//字典，用于查找答案
    private LinkedList<Word> test = new LinkedList<Word>();//测试的词库
    private Socket socket;

    public void loadWord() {
        dictionary.put("你好", "hello");
        dictionary.put("早上", "morning");
        dictionary.put("知名运动品牌（耐克）", "nike");
        dictionary.put("英国人", "English");
        dictionary.put("日本人", "Japanese");
        dictionary.put("中国人", "Chinese");
        dictionary.put("德国人", "Germany");
        dictionary.put("经济的", "economic");
        dictionary.put("生态系统", "ecosystem");
        dictionary.put("经济", "economy");
        test.add(new Word("hello", "你好", "早上", "英国人", "经济的"));
        test.add(new Word("morning", "早上", "中国人", "生态系统", "经济的"));
        test.add(new Word("nike", "经济的", "生态系统", "日本人", "知名运动品牌（耐克）"));
        test.add(new Word("ecosystem", "生态系统", "经济的", "知名运动品牌（耐克）", "日本人"));
        test.add(new Word("Chinese", "德国人", "日本人", "中国人", "英国人"));
        test.add(new Word("Japanese", "德国人", "日本人", "中国人", "英国人"));
        test.add(new Word("Germany", "德国人", "日本人", "中国人", "英国人"));
        test.add(new Word("English", "德国人", "日本人", "中国人", "英国人"));
        test.add(new Word("economic", "你好", "生态系统", "经济的", "早上"));
        test.add(new Word("economy", "生态系统", "经济", "经济的", "德国人"));
        //使得单词出现随机
        Collections.shuffle(test);
    }

    public Server(int port) throws IOException {
        this.port = port;
        serverSocket = new ServerSocket(port);
        loadWord();
    }

    public void Send() throws IOException {
        //连接客户端
        socket = serverSocket.accept();
        OutputStream os = socket.getOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(os);
        for (int i = 0; i < 10; i++) {
            //获取题目
            Word sendWord = test.getFirst();
            //将题目送往客户端
            oos.writeObject(sendWord);
            InputStream is = socket.getInputStream();
            //获取客户端选择的结果
            byte[] receiveData = new byte[1024];
            int len;
            len = is.read(receiveData);
            String s = new String(receiveData, 0, len);
            String answer = dictionary.get(s);
            //判断结果是否正确，正确则放回True，否则放回false
            if (answer.equals(sendWord.english)) {
                os.write("True".getBytes());
                System.out.println("true");
            } else {
                os.write("False".getBytes());
                System.out.println("false");
            }
            test.removeFirst();
        }
        //关闭流
        oos.close();
        os.close();
        socket.close();
    }


}
