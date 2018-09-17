package com.company;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class Demultiplexer implements Runnable{

    private Socket socket;
    private HandleMap handleMap;

    private final int HEADER_SIZE = 6;

    public Demultiplexer(Socket socket, HandleMap handleMap) {
        this.socket = socket;
        this.handleMap = handleMap;
    }

    @Override
    public void run() {
        InputStream inputStream = null;
        try {
            inputStream = socket.getInputStream();

            byte[] buffer = new byte[HEADER_SIZE];
            inputStream.read(buffer);
            String header = new String(buffer);

            handleMap.get(header).handleEvent(inputStream);

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
