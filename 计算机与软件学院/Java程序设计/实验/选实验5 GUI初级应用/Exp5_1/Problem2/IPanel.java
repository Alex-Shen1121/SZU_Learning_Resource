package Exp5_1.Problem2;

import javax.swing.*;
import java.awt.*;

public class IPanel extends JPanel {
    private String imagePath = "";
    private Image img = null;
    private int width = 50;
    private int height = 50;

    public void setImagePath(String URL) {
        imagePath = URL;
    }

    public void setWidth(int _width) {
        width = _width;
    }

    public void setHeight(int _height) {
        height = _height;
    }

    public void paintComponent(Graphics g) {
        img = new ImageIcon(imagePath).getImage();
        g.drawImage(img, 0, 0, width, height, this);
    }
}
