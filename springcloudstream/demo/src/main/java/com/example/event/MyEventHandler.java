package com.example.event;

import org.springframework.context.event.EventListener;
import org.springframework.stereotype.Component;

@Component
public class MyEventHandler {
    @EventListener
    public void handler(MyEvent e){
        System.out.println("Event received : "+ e);
    }
}
