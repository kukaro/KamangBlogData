package com.company;

import java.io.InputStream;

public interface EventHandler {
    String getHandler();

    void handleEvent(InputStream inputStream);

}
