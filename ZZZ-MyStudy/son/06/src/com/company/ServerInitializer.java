package com.company;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.channels.AsynchronousChannelGroup;
import java.nio.channels.AsynchronousServerSocketChannel;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServerInitializer {

    private static final int PORT = 5000;
    private static final int threadPoolSize = 8;
    private static final int initialSize = 4;
    private static final int backlog = 50;

    public static void main(String[] args) {
        System.out.println("SERVER START!");

        ExecutorService executor = Executors.newFixedThreadPool(threadPoolSize);

        try{
            AsynchronousChannelGroup group = AsynchronousChannelGroup.withCachedThreadPool(executor, initialSize);
            AsynchronousServerSocketChannel listener = AsynchronousServerSocketChannel.open(group);
            listener.bind(new InetSocketAddress(PORT), backlog);

            listener.accept(listener,new Dispatcher());
        }catch (IOException e){
            e.printStackTrace();
        }

    }
}
