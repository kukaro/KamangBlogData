package com.example.loggingconsumer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.messaging.handler.annotation.SendTo;

@SpringBootApplication
@EnableBinding(Processor.class)
public class LoggingConsumerApplication {
    public static void main(String[] args) {
        SpringApplication.run(LoggingConsumerApplication.class, args);
    }

    @Autowired
    WireBinding binding;

    @Autowired
    Sink sink;

    @StreamListener(Processor.INPUT)
    @SendTo(Processor.OUTPUT)
    public String handler(String str) {
        System.out.println("Received : " + str);
        binding.sayHello(str);
        return str + "!!";
    }
}
