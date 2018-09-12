package com.company;

import java.io.IOException;
import java.io.InputStream;
import java.util.StringTokenizer;


public class StreamUpdateProfileProtocol {

    private static final int DATA_SIZE = 1024;
    private static final int TOKEN_NUM = 5;

    @SuppressWarnings("Duplicates")
    public void handleEvent(InputStream inputStream) {
        try {
            byte[] buffer = new byte[DATA_SIZE];
            inputStream.read(buffer);
            String data = new String(buffer);

            String[] params = new String[TOKEN_NUM];
            StringTokenizer stringTokenizer = new StringTokenizer(data, "|");

            int i = 0;
            while (stringTokenizer.hasMoreTokens() && i!=TOKEN_NUM) {
                params[i] = stringTokenizer.nextToken();
                i++;
            }

            sayHello(params);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void sayHello(String[] params) {
        System.out.println("SayHello ->" +
                " id : " + params[0] +
                " password : " + params[1] +
                " name : " + params[2] +
                " age : " + params[3] +
                " gender : " + params[4]);
    }
}
