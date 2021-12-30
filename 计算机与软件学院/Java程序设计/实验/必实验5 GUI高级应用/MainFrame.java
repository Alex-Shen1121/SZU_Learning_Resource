package Exp5_2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.List;
import java.util.*;

class Word {
    String chinese;
    String[] english;

    public Word(String chinese, String e1, String e2, String e3, String e4, String e5) {
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

public class MainFrame extends Frame implements Runnable {
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
    private LinkedList<Word> singletest = new LinkedList<Word>();//单选的词库
    private LinkedList<Word> multitest = new LinkedList<Word>();//测试的词库
    private HashMap<String, ArrayList<String>> dictionary = new HashMap<>();//字典，用于查找答案


    public MainFrame() {
        dictionary.put("你好", new ArrayList<String>(List.of("Hello")));
        dictionary.put("早上", new ArrayList<String>(List.of("morning")));
        dictionary.put("知名运动品牌（耐克）", new ArrayList<String>(List.of("nike")));
        dictionary.put("英国人", new ArrayList<String>(List.of("English")));
        dictionary.put("日本人", new ArrayList<String>(List.of("Japanese")));
        dictionary.put("中国人", new ArrayList<String>(List.of("Chinese")));
        dictionary.put("德国人", new ArrayList<String>(List.of("Germany")));
        dictionary.put("经济的", new ArrayList<String>(List.of("economic")));
        dictionary.put("生态系统", new ArrayList<String>(List.of("ecosystem")));
        dictionary.put("昨天", new ArrayList<String>(List.of("yesterday")));
        dictionary.put("捕获者", new ArrayList<String>(List.of("captor")));
        dictionary.put("宣布", new ArrayList<String>(List.of("announce")));
        dictionary.put("需求", new ArrayList<String>(List.of("demand")));
        dictionary.put("绑架", new ArrayList<String>(List.of("abduct")));
        dictionary.put("省会", new ArrayList<String>(List.of("capital")));
        dictionary.put("孤儿院", new ArrayList<String>(List.of("orphanage")));
        dictionary.put("问题", new ArrayList<String>(List.of("problem")));
        dictionary.put("发言人", new ArrayList<String>(List.of("spokesman")));
        dictionary.put("星座", new ArrayList<String>(List.of("constellation")));
        dictionary.put("孩子们", new ArrayList<String>(List.of("children")));
        dictionary.put("古迹", new ArrayList<String>(List.of("historical site", "monument")));
        dictionary.put("裁缝", new ArrayList<String>(List.of("dressmaker", "tailor")));
        dictionary.put("参赛者", new ArrayList<String>(List.of("participant", "competitor")));
        dictionary.put("算法", new ArrayList<String>(List.of("arithmetic", "algorithm")));
        dictionary.put("总共", new ArrayList<String>(List.of("in all", "in total", "altogether")));
        dictionary.put("卫兵", new ArrayList<String>(List.of("guard", "bodyguard")));
        dictionary.put("精准", new ArrayList<String>(List.of("precise", "accurate")));


        singletest.add(new Word("你好", "hello", "morning", "nike", "good", "economic"));
        singletest.add(new Word("早上", "hello", "morning", "nike", "good", "economic"));
        singletest.add(new Word("知名运动品牌（耐克）", "hello", "morning", "nike", "good", "economic"));
        singletest.add(new Word("好", "hello", "morning", "nike", "good", "economic"));
        singletest.add(new Word("中国人", "Chinese", "English", "Japanese", "Germany", "economic"));
        singletest.add(new Word("英国人", "Chinese", "English", "Japanese", "Germany", "economic"));
        singletest.add(new Word("日本人", "Chinese", "English", "Japanese", "Germany", "economic"));
        singletest.add(new Word("德国人", "Chinese", "English", "Japanese", "Germany", "economic"));
        singletest.add(new Word("经济的", "economic", "economy", "ecosystem", "economics", "economic"));
        singletest.add(new Word("生态系统", "economic", "economy", "ecosystem", "guard", "economic"));
        singletest.add(new Word("昨天", "yesterday", "announce", "captor", "demand", "economic"));
        singletest.add(new Word("捕获者", "announce", "abduct", "orphanage", "economic", "captor"));
        singletest.add(new Word("宣布", "announce", "guard", "capital", "demand", "economic"));
        singletest.add(new Word("需求", "captor", "demand", "yesterday", "abduct", "economic"));
        singletest.add(new Word("绑架", "problem", "abduct", "captor", "spokesman", "economic"));
        singletest.add(new Word("省会", "guard", "constellation", "capital", "capital", "economic"));
        singletest.add(new Word("孤儿院", "orphanage", "problem", "constellation", "yesterday", "economic"));
        singletest.add(new Word("问题", "problem", "captor", "abduct", "demand", "economic"));
        singletest.add(new Word("发言人", "capital", "demand", "announce", "spokesman", "economic"));
        singletest.add(new Word("星座", "constellation", "capital", "abduct", "economic", "spokesman"));
        multitest.add(new Word("卫兵", "guard", "bodyguard", "constellation", "orphanage", "economic"));
        multitest.add(new Word("精准", "children", "precise", "accurate", "economic", "spokesman"));
        multitest.add(new Word("古迹", "historical site", "monument", "yesterday", "good", "economic"));
        multitest.add(new Word("裁缝", "constellation", "dressmaker", "tailor", "spokesman", "economic"));
        multitest.add(new Word("算法", "arithmetic", "monument", "yesterday", "algorithm", "economic"));
        multitest.add(new Word("参赛者", "participant", "monument", "yesterday", "competitor", "economic"));
        multitest.add(new Word("总共", "historical site", "in all", "yesterday", "in total", "altogether"));


        //使得单词出现随机
        Collections.shuffle(singletest);
        Collections.shuffle(multitest);
    }

    public void init() {
        this.setTitle("单机版中英文单词测试程序");
        //添加组件
        hint = new JLabel("首先进行的是《中译英》单词测试。前五题为多选题，六至十五题为多选题。");
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
        Word word = (no <= 5) ? multitest.getFirst() : singletest.getFirst();
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
        MainFrame mainFrame = new MainFrame();
        new Thread(mainFrame).start();
        mainFrame.init();
    }


}
