package Exp5_2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.List;
import java.util.*;

class Word2 {
    String chinese;
    String[] english;

    public Word2(String chinese, String e1, String e2, String e3, String e4, String e5) {
        this.chinese = chinese;
        english = new String[5];
        english[0] = e1;
        english[1] = e2;
        english[2] = e3;
        english[3] = e4;
        english[4] = e5;
    }

    public String getChinese() {
        return chinese;
    }

    public void setChinese(String chinese) {
        this.chinese = chinese;
    }

    public String[] getEnglish() {
        return english;
    }

    public void setEnglish(String[] english) {
        this.english = english;
    }
}

public class MainFrame2 extends Frame implements Runnable {
    private JPanel mainpan = new JPanel();
    private JPanel header = new JPanel();
    private boolean isAdd = false;//设置此标签防止一题答对，多次计分
    private boolean isStart = false;
    private int no = 0;//题号
    private int mark = 0;//答对的题目数量
    private JLabel labelNo = new JLabel("第" + no + "题");
    private JLabel labelMark = new JLabel("总得" + mark + "分");
    private JLabel labelFeedback = new JLabel("");
    private JTextField userAnswer = new JTextField();
    JButton submit = new JButton("提交");
    private JLabel chinese;//中文
    private JLabel hint;//提示
    private JLabel[] english = new JLabel[5];//英文解释选项
    private LinkedList<Word2> singletest = new LinkedList<Word2>();//单选的词库
    private LinkedList<Word2> multitest = new LinkedList<Word2>();//测试的词库
    private HashMap<String, ArrayList<String>> dictionary = new HashMap<>();//字典，用于查找答案


    public MainFrame2() {
        dictionary.put("Hello", new ArrayList<String>(List.of("你好")));
        dictionary.put("morning", new ArrayList<String>(List.of("早上")));
        dictionary.put("nike", new ArrayList<String>(List.of("知名运动品牌（耐克）")));
        dictionary.put("English", new ArrayList<String>(List.of("英国人")));
        dictionary.put("Japanese", new ArrayList<String>(List.of("日本人")));
        dictionary.put("Chinese", new ArrayList<String>(List.of("中国人")));
        dictionary.put("Germany", new ArrayList<String>(List.of("德国人")));
        dictionary.put("economic", new ArrayList<String>(List.of("经济的")));
        dictionary.put("ecosystem", new ArrayList<String>(List.of("生态系统")));
        dictionary.put("yesterday", new ArrayList<String>(List.of("昨天")));
        dictionary.put("captor", new ArrayList<String>(List.of("捕获者")));
        dictionary.put("announce", new ArrayList<String>(List.of("宣布")));
        dictionary.put("demand", new ArrayList<String>(List.of("需求")));
        dictionary.put("abduct", new ArrayList<String>(List.of("绑架")));
        dictionary.put("capital", new ArrayList<String>(List.of("首都")));
        dictionary.put("orphanage", new ArrayList<String>(List.of("孤儿院")));
        dictionary.put("problem", new ArrayList<String>(List.of("问题")));
        dictionary.put("spokesman", new ArrayList<String>(List.of("发言人")));
        dictionary.put("constellation", new ArrayList<String>(List.of("星座")));
        dictionary.put("children", new ArrayList<String>(List.of("孩子们")));

        dictionary.put("fear", new ArrayList<String>(List.of("害怕", "恐惧")));
        dictionary.put("expel", new ArrayList<String>(List.of("把...开除", "驱逐")));
        dictionary.put("component", new ArrayList<String>(List.of("成分", "部件")));
        dictionary.put("algorithm", new ArrayList<String>(List.of("算法", "运算法则")));
        dictionary.put("guard", new ArrayList<String>(List.of("卫兵", "警卫", "看守")));
        dictionary.put("accurate", new ArrayList<String>(List.of("准确的", "精密的")));
        dictionary.put("participant", new ArrayList<String>(List.of("参加者", "参与者")));


        singletest.add(new Word2("Hello", "绑架", "你好", "成分", "捕获者", "部件"));
        singletest.add(new Word2("morning", "中国人", "成分", "早上", "生态系统", "宣布"));
        singletest.add(new Word2("nike", "绑架", "知名运动品牌（耐克）", "中国人", "生态系统", "孤儿院"));
        singletest.add(new Word2("English", "英国人", "星座", "成分", "捕获者", "生态系统"));
        singletest.add(new Word2("Japanese", "静谧的", "星座", "日本人", "运算法则", "部件"));
        singletest.add(new Word2("Chinese", "静谧的", "德国人", "成分", "中国人", "宣布"));
        singletest.add(new Word2("Germany", "运算法则", "德国人", "成分", "运算法则", "中国人"));
        singletest.add(new Word2("economic", "经济的", "静谧的", "绑架", "中国人", "部件"));
        singletest.add(new Word2("ecosystem", "孤儿院", "运算法则", "宣布", "宣布", "生态系统"));
        singletest.add(new Word2("yesterday", "运算法则", "昨天", "静谧的", "参加者", "中国人"));
        singletest.add(new Word2("captor", "捕获者", "成分", "captor", "成分", "捕获者"));
        singletest.add(new Word2("announce", "孤儿院", "宣布", "绑架", "德国人", "静谧的"));
        singletest.add(new Word2("demand", "生态系统", "星座", "成分", "德国人", "部件"));
        singletest.add(new Word2("abduct", "星座", "孤儿院", "捕获者", "绑架", "部件"));
        singletest.add(new Word2("capital", "运算法则", "绑架", "成分", "德国人", "首都"));
        singletest.add(new Word2("orphanage", "绑架", "宣布", "生态系统", "孤儿院", "中国人"));
        singletest.add(new Word2("problem", "星座", "德国人", "问题", "静谧的", "运算法则"));
        singletest.add(new Word2("spokeman", "生态系统", "发言人", "捕获者", "成分", "捕获者"));
        singletest.add(new Word2("constellation", "星座", "静谧的", "成分", "中国人", "运算法则"));
        singletest.add(new Word2("children", "捕获者", "孩子们", "绑架", "宣布", "捕获者"));

        multitest.add(new Word2("fear", "中国人", "害怕", "部件", "成分", "恐惧"));
        multitest.add(new Word2("expel", "把...开除", "德国人", "部件", "驱逐", "孤儿院"));
        multitest.add(new Word2("component", "成分", "部件", "成分", "星座", "宣布"));
        multitest.add(new Word2("algorithm", "捕获者", "算法", "星座", "运算法则", "参加者"));
        multitest.add(new Word2("guard", "成分", "成分", "卫兵", "警卫", "看守"));
        multitest.add(new Word2("accurate", "精密的", "准确的", "静谧的", "绑架", "孤儿院"));
        multitest.add(new Word2("participant", "捕获者", "参加者", "宣布", "参与者", "星座"));


        //使得单词出现随机
        Collections.shuffle(singletest);
        Collections.shuffle(multitest);
    }

    public void init() {
        this.setTitle("单机版中英文单词测试程序");
        //添加组件
        hint = new JLabel("首先进行的是《英译中》单词测试。前五题为多选题，六至十五题为多选题。");
        chinese = new JLabel("欢迎使用单词测试");
        this.setLayout(new BorderLayout());
        this.add(mainpan, BorderLayout.CENTER);
        mainpan.setLayout(new GridLayout(8, 1));
        mainpan.add(hint);
        mainpan.add(chinese);
        mainpan.add(userAnswer);
        for (int i = 0; i < english.length; i++) {
            english[i] = new JLabel();
            mainpan.add(english[i]);
        }
        header.add(submit);
        header.add(labelNo);
        header.add(labelFeedback);
        header.add(labelMark);
        this.setResizable(false);
        this.add(header, BorderLayout.SOUTH);
        this.setSize(500, 600);
        this.setLocation(300, 300);
        this.setVisible(true);

        //事件添加
        //关闭程序事件
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        //用户输入事件
        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!isAdd && isStart) {//此题没答对过并且以及开始测试，设置此标签防止一题答对，多次计分
                    JTextField textField = userAnswer;
                    String ans = textField.getText().trim();
                    String regex = "\\w{1,5}";  // 匹配1-5个字符
                    boolean isVaild = ans.matches(regex);//判断其输入是否是”ABCDE"其中之一个或者多个
                    if (isVaild) {
                        System.out.println(ans);
                        boolean flag = true;
                        for (int i = 0; i < ans.length(); i++) {
                            int index = ans.charAt(i) - 'A';
                            //找到选项代表的英文解释
                            String choosed = english[index].getText().substring(4);
                            // 去答案库中匹配是否存在该英语解释
                            if (dictionary.get(chinese.getText()).contains(choosed)) {
                                // 正确选项设置为绿色
                                english[index].setForeground(Color.green);
                            } else {
                                //提示答案错误，设置为红色
                                english[index].setForeground(Color.red);
                                flag = false;
                            }
                        }
                        // 用户输入答案与答案库答案长度不同 为少选或多选
                        if (ans.length() != dictionary.get(chinese.getText()).size()) {
                            labelFeedback.setText("回答错误，少选或多选！");
                            labelMark.setText("总得" + mark + "分");
                        } else if (flag) {  // 完全正确
                            if (dictionary.get(chinese.getText()).size() > 1) mark += 10;
                            else mark += 5;
                            isAdd = true;
                            labelFeedback.setText("回答正确！");
                            labelMark.setText("总得" + mark + "分");
                        } else {    // 包含错误答案
                            labelFeedback.setText("回答错误！");
                            labelMark.setText("总得" + mark + "分");
                        }
                    }
                    else
                        userAnswer.setText("");
                }
            }
        });
    }

    private void giveWord() {
        try {
            Thread.sleep(10000);//先休眠10s
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        isAdd = false;
        labelNo.setText("第" + (++no) + "题");
        labelFeedback.setText("");
        labelMark.setText("总得" + mark + "分");
        // 判断出题题库来源
        Word2 word = (no <= 5) ? multitest.getFirst() : singletest.getFirst();
        chinese.setText(word.chinese);
        for (int i = 0; i < ((no <= 5) ? 5 : 4); i++) {
            english[i].setText((char) ('A' + i) + ".  " + word.english[i]);
            english[i].setForeground(Color.BLACK);
        }
        //开始测试
        isStart = true;
        singletest.removeFirst();
        multitest.removeFirst();
        //清空输入，使得使用者不用手动清空上一题的选项
        userAnswer.setText("");
    }

    public void run() {
        //循环15次，出15道题目
        int count = 15;
        while (count-- != 0) {
            giveWord();
            //清空输入，使得使用者不用手动清空提交的选项
            userAnswer.setText("");
        }
        //程序结束后，答题界面清空
        isStart = false;
        chinese.setText("");
        hint.setText("");
        for (int i = 0; i < 5; i++) {
            english[i].setText("");
        }
    }

    public static void main(String[] args) {
        MainFrame2 mainFrame = new MainFrame2();
        new Thread(mainFrame).start();
        mainFrame.init();
    }


}
