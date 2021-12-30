package 实验二;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.util.HashMap;
import java.util.LinkedList;

class Word implements Serializable {
    String english;
    String[] Chinese;

    public Word(String english, String e1, String e2, String e3, String e4) {
        this.english = english;
        Chinese = new String[4];
        Chinese[0] = e1;
        Chinese[1] = e2;
        Chinese[2] = e3;
        Chinese[3] = e4;
    }

    public String getEnglish() {
        return english;
    }

    public void setEnglish(String english) {
        this.english = english;
    }

    public String[] getChinese() {
        return Chinese;
    }

    public void setChinese(String[] chinese) {
        this.Chinese = chinese;
    }
}

public class MainFrame extends Frame implements Runnable {
    private JPanel mainpan = new JPanel();
    private JPanel header = new JPanel();
    private boolean isAdd = false;//设置此标签防止一题答对，多次计分
    private boolean isStart = false;
    private int no = 0;//题号
    private int mark = 0;//答对的题目数量
    private JLabel labelNo = new JLabel("第" + no + "题");
    private JLabel labelMark = new JLabel("总得" + mark + "分");
    private JTextField userAnswer = new JTextField();
    private JLabel english;//中文
    private JLabel[] chinese = new JLabel[4];//英文解释选项
    private LinkedList<Word> test = new LinkedList<Word>();//测试的词库
    private HashMap<String, String> dictionary = new HashMap<>();//字典，用于查找答案
    private Socket socket;
    public static boolean isReadyNext;

    public MainFrame(String Ip, int port) throws Exception {
        socket = new Socket(InetAddress.getByName(Ip), port);
    }

    public void init() {
        this.setTitle("单机版中英文单词测试程序");
        //添加组件
        english = new JLabel("你好,欢迎使用单词测试");
        this.setLayout(new BorderLayout());
        //事件添加
        //关闭程序事件
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        //用户输入事件
        userAnswer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!isAdd && isStart) {//此题没答对过并且以及开始测试，设置此标签防止一题答对，多次计分
                    JTextField textField = userAnswer;
                    String ans = textField.getText().trim();
                    //清空输入，使得使用者不用手动清空提交的选项
                    userAnswer.setText("");
                    String regex = "[ABCD]";
                    Boolean isVaild = ans.matches(regex);//判断其输入是否是”ABCD"其中之一
                    if (isVaild) {
                        System.out.println(ans);
                        int index = ans.charAt(0) - 'A';
                        String choosed = chinese[index].getText().substring(4, chinese[index].getText().length());//找到选项代表的中文解释
                        //发送所选择的答案
                        OutputStream os;
                        InputStream is;
                        String result = null;
                        byte[] receiveResult = new byte[1024];
                        int len = 0;
                        try {
                            os = socket.getOutputStream();
                            os.write(choosed.getBytes());

                        } catch (IOException e1) {
                            e1.printStackTrace();
                        }
                    }
                }
            }
        });
        //布局
        mainpan.setLayout(new GridLayout(6, 1));
        mainpan.add(english);
        mainpan.add(userAnswer);
        for (int i = 0; i < chinese.length; i++) {
            chinese[i] = new JLabel();
            mainpan.add(chinese[i]);
        }
        header.add(labelNo);
        header.add(labelMark);
//        this.setResizable(false);
        this.add(header, BorderLayout.NORTH);
        this.add(new JPanel(), BorderLayout.SOUTH);

        this.add(mainpan);
        this.add(new JPanel(), BorderLayout.WEST);
        this.add(new JPanel(), BorderLayout.EAST);
        this.setSize(400, 200);
        this.setLocation(300, 300);
        mainpan.setBounds(50, 50, 80, 80);

        this.setVisible(true);
    }

    private void giveWord() throws IOException, ClassNotFoundException {
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        ObjectInputStream ois = new ObjectInputStream(is);
        byte[] receiveData = new byte[1024];
        int t=10;
        while (t--!=0) {
            isAdd = false;
            labelNo.setText("第" + (++no) + "题");
            //接收服务器端发送的word对象
            Word receiveWord = (Word) (ois.readObject());
            //更新GUI题目界面
            test.add(receiveWord);
            Word word = test.getFirst();
            english.setText(word.english);
            for (int i = 0; i < 4; i++) {
                chinese[i].setText((char) ('A' + i) + ".  " + word.Chinese[i]);
                chinese[i].setForeground(Color.BLACK);
            }
            //开始测试
            isStart = true;
            test.removeFirst();
            //读取服务器判断的结果
            int len = 0;
            String result = null;
            byte[] receiveResult = new byte[1024];
            len = is.read(receiveResult);
            result = new String(receiveResult, 0, len);
            //如果答案正确，分数+1
            if (result.equals("True")) {
                mark++;
                labelMark.setText("总得" + mark + "分");
                isAdd = true;
            }

        }
    }

    public void run() {
        try {
            giveWord();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

//        程序结束后，答题界面清空
        isStart = false;
        english.setText("");
        for (int i = 0; i < 4; i++) {
            chinese[i].setText("");
        }
    }


}
