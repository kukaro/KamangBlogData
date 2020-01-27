package com.example.loggingconsumer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.handler.annotation.Payload;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Component;

@Component
public class WireBinding {
    @Autowired
    private Source source;

    public void sayHello(String name){
        source.output().send(MessageBuilder.withPayload("!!"+name+"!!").build());
    }
}
