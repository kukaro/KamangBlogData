package com.company;

import org.simpleframework.xml.Serializer;
import org.simpleframework.xml.core.Persister;

import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.util.List;

public class ServerInitializer {

    public static void main(String[] args) {
        int port = 5000;
        System.out.println("Server ON : " + port);

        Reactor reactor = new Reactor(port);

        try {
            Serializer serializer = new Persister();
            File source = new File("HandlerList.xml");
            ServerListData serverListData = serializer.read(ServerListData.class, source);

            for (HandlerListData handlerListData : serverListData.getServer()) {
                if("server1".equals(handlerListData.getName())){
                    List<HandlerData> handlerList = handlerListData.getHandler();
                    for(HandlerData handlerData:handlerList){
                        reactor.registerHandler(handlerData.getHeader(),(EventHandler)Class.forName(handlerData.getHandler()).newInstance());
                    }
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
        reactor.startServer();
    }
}
