package com.company;

import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class ThreadPerDispatcher implements Dispatcher{

    private final int HEADER_SIZE = 6;

    @Override
    public void dispatch(ServerSocket serverSocket, HandleMap handleMap) {
        while(true){
            try {
                /*
                 * accept에서 서버가 멈춘다.
                 */
                Socket socket = serverSocket.accept();
                demultiplex(socket, handleMap);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void demultiplex(Socket socket, HandleMap handleMap) {
        try {
            InputStream inputStream = socket.getInputStream();

            Runnable demultiplexer = new Demultiplexer(socket, handleMap);
            Thread thread = new Thread(demultiplexer);
            thread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
