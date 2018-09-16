package com.company;

import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class Dispatcher {

    private final int HEADER_SIZE = 6;

    public void dispatch(ServerSocket serverSocket, HandleMap handleMap) {
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

    private void demultiplex(Socket socket, HandleMap handleMap) {
        try {
            InputStream inputStream = socket.getInputStream();
            byte[] buffer = new byte[HEADER_SIZE];
            inputStream.read(buffer);
            String header = new String(buffer);
//            for (Map.Entry atom : handleMap.entrySet()) {
//                System.out.println(atom.getKey() + ":" + atom.getValue());
//            }
            handleMap.get(header).handleEvent(inputStream);

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
