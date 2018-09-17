package com.company;

import java.net.ServerSocket;

public interface Dispatcher {
    void dispatch(ServerSocket serverSocket, HandleMap handleMap);
}
