package net.theceres.gui;

import net.theceres.main.ResTxt;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;

public class MyFrame extends JFrame {

    public MyFrame(int width, int height) {
        setSize(width, height);
        setContentPane(new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                try {
                    ImageIcon ii = new ImageIcon(new File(getClass().getResource("").getPath()).getCanonicalFile().getPath());
                    System.out.println(new File(MyFrame.class.getResource("").getPath()+"/../.../resource/img/index.jpeg").getCanonicalFile().getPath());
                    Image img = ii.getImage();
                    g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), this);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        //setTitle(ResTxt.getS("title"));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
