package Exp5_1.Problem2;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class MFrame {
    Frame frame;
    FileDialog openDia;
    private IPanel iPanel;

    public MFrame() {
        frame = new Frame("Image Browser"); // 创建窗体对象
        frame.setSize(1000, 1000);
        MenuBar bar = new MenuBar();    // 创建菜单栏
        Menu fileMenu = new Menu("document");   // 创建文件菜单
        MenuItem openItem = new MenuItem("open");   // 创建打开菜单栏
        openDia = new FileDialog(frame, "打开", FileDialog.LOAD);
        frame.setLayout(new BorderLayout());
        fileMenu.add(openItem); // 将打开菜单项添加到文件菜单上
        bar.add(fileMenu);  // 将文件添加到菜单栏上
        frame.setMenuBar(bar);  // 将此窗体的菜单栏设置为指定的菜单栏

        JPanel pan = new JPanel();  // pan中放入JButton和JLable
        pan.add(new JLabel("清空"));
        JButton JClear = new JButton("clear");
        pan.add(JClear);
        pan.setBackground(Color.lightGray);

        frame.add(pan, BorderLayout.NORTH);
        iPanel = new IPanel();
        JClear.addActionListener(new ActionListener() {
            @Override
            // 清空按钮，使画板不可见
            public void actionPerformed(ActionEvent e) {
                iPanel.setVisible(false);
            }
        });
        frame.add(iPanel, BorderLayout.CENTER);
        myEvent(openItem);
        frame.validate();
        frame.setVisible(true);
    }

    public void myEvent(MenuItem openItem) {
        openItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                openDia.setVisible(true);
                String dirpath = openDia.getDirectory(); // 获取打开文件路径并保存到字符串中
                String fileName = openDia.getFile();
                System.out.println(dirpath + ' ' + fileName);
                try {
                    BufferedImage image = ImageIO.read(new File(dirpath + fileName));
                    iPanel.setWidth(image.getWidth());
                    iPanel.setHeight(image.getHeight());
                } catch (IOException ex) {
                    ex.printStackTrace();
                }

                // 清楚clear的影响
                iPanel.setVisible(true);
                iPanel.setImagePath(dirpath + fileName);
                iPanel.repaint();
            }
        });

        // 窗体关闭
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        MFrame mFrame = new MFrame();
    }
}
