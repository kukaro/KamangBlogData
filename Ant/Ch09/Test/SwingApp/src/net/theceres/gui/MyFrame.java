package net.theceres.gui;

import resource.text.ResTxt;

import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {

    public MyFrame(int width,int height){
        setSize(width,height);
        setContentPane(new JPanel(){
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                ImageIcon ii = new ImageIcon(getClass().getResource("/resource/img/index.jpeg"));
                Image img = ii.getImage();
                g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), this);
            }
        });
        setTitle(ResTxt.getS("title"));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
