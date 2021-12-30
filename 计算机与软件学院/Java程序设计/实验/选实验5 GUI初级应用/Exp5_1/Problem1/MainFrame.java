package Exp5_1.Problem1;

import com.baidu.translate.demo.TransApi;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;
import java.util.StringTokenizer;

class MainFrame implements ActionListener {
    public JFrame jFrame;
    private JPanel whole = new JPanel();
    private JTextField[] textField = new JTextField[4];

    // 在平台申请的APP_ID 详见 http://api.fanyi.baidu.com/api/trans/product/desktop?req=developer
    private static final String APP_ID = "20211208001021977";
    private static final String SECURITY_KEY = "D4sednFFWcS8CLBBOJfx";


    public MainFrame() {
        // 生成主画面
        jFrame = new JFrame();
        jFrame.setName("Translator");
        jFrame.add(whole);
        jFrame.setLocation(500, 500);
        jFrame.setSize(400, 400);
        whole.setLayout(new GridLayout(4, 1));
        whole.add(createPanel("中文", "Chinese"));
        whole.add(createPanel("英语", "English"));
        whole.add(createPanel("德语", "German"));
        whole.add(createPanel("法语", "French"));

        jFrame.pack();
        jFrame.validate();
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.setVisible(true);
    }

    // 创建面板：包含文本框，标签，按钮
    public JPanel createPanel(String title, String name) {
        JPanel pan = new JPanel();
        new BoxLayout(pan, BoxLayout.X_AXIS);
        JLabel jLabel = new JLabel(title);
        JTextField jTextField = new JTextField("",30);
        int index = 1;
        if (Objects.equals(title, "中文")) index = 0;
        else if (Objects.equals(title, "英语")) index = 1;
        else if (Objects.equals(title, "德语")) index = 2;
        else if (Objects.equals(title, "法语")) index = 3;
        textField[index] = jTextField;
        // 设置监听
        JButton jButton = new JButton(name);
        jButton.setActionCommand(name);
        jButton.addActionListener(this);
        // pan中加入控件
        pan.add(jLabel);
        pan.add(jTextField);
        pan.add(jButton);
        pan.setSize(20, 20);
        return pan;
    }

    // 监听按钮
    @Override
    public void actionPerformed(ActionEvent e) {

        String cmd = e.getActionCommand();
        JTextField[] target = new JTextField[4]; // 输出的目标文本框
        for (int i = 0; i < 4; i++) {
            target[i] = (JTextField) textField[i];
        }
        String input;
        TransApi api = new TransApi(APP_ID, SECURITY_KEY);
        String temp = null;
        StringTokenizer token;
        if (Objects.equals(cmd, "Chinese")) {
            JTextField chineseField = (JTextField) textField[0];
            // 获得输入
            input = chineseField.getText().trim();
            // 翻译成英文并解析json
            token = new StringTokenizer(api.getTransResult(input, "zh", "en"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[1].setText(temp);

            // 翻译成德语并解析json
            token = new StringTokenizer(api.getTransResult(input, "zh", "de"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[2].setText(temp);

            // 翻译成法语并解析json
            token = new StringTokenizer(api.getTransResult(input, "zh", "fra"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[3].setText(temp);
        }
        else if (Objects.equals(cmd, "English")) {
            JTextField Field = (JTextField) textField[1];
            // 获得输入
            input = Field.getText().trim();
            // 翻译成中文并解析json
            token = new StringTokenizer(api.getTransResult(input, "en", "zh"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            temp=UnicodeConvertUtil.revert(temp);
            target[0].setText(temp);

            // 翻译成德语并解析json
            token = new StringTokenizer(api.getTransResult(input, "en", "de"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[2].setText(temp);

            // 翻译成法语并解析json
            token = new StringTokenizer(api.getTransResult(input, "en", "fra"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[3].setText(temp);
        }
        else if (Objects.equals(cmd, "German")) {
            JTextField Field = (JTextField) textField[2];
            // 获得输入
            input = Field.getText().trim();
            // 翻译成中文并解析json
            token = new StringTokenizer(api.getTransResult(input, "de", "zh"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            temp=UnicodeConvertUtil.revert(temp);
            target[0].setText(temp);

            // 翻译成英语并解析json
            token = new StringTokenizer(api.getTransResult(input, "de", "en"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[1].setText(temp);

            // 翻译成法语并解析json
            token = new StringTokenizer(api.getTransResult(input, "de", "fra"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[3].setText(temp);
        }
        else if (Objects.equals(cmd, "French")) {
            JTextField Field = (JTextField) textField[3];
            // 获得输入
            input = Field.getText().trim();
            // 翻译成中文并解析json
            token = new StringTokenizer(api.getTransResult(input, "fra", "zh"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            temp=UnicodeConvertUtil.revert(temp);
            target[0].setText(temp);

            // 翻译成德语并解析json
            token = new StringTokenizer(api.getTransResult(input, "fra", "de"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[2].setText(temp);

            // 翻译成英语并解析json
            token = new StringTokenizer(api.getTransResult(input, "fra", "fra"), "\"}]}");
            while(token.hasMoreTokens()){
                temp = token.nextToken();
            }
            target[1].setText(temp);
        }
    }
}
