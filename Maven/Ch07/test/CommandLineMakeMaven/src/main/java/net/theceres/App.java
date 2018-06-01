package net.theceres;

import javazoom.jl.player.Player;

import java.io.FileInputStream;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        try {
            FileInputStream fileInputStream = new FileInputStream("/Users/kukaro/Desktop/music/Uplink - Crying Over You [NCS Release].mp3");
            Player player = new Player(fileInputStream);
            player.play();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
