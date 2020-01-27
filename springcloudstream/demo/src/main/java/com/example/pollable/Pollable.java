package com.example.pollable;

import org.springframework.boot.ApplicationRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.cloud.stream.binder.PollableMessageSource;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.context.annotation.Bean;
import org.springframework.integration.annotation.InboundChannelAdapter;
import org.springframework.integration.annotation.Poller;
import org.springframework.integration.core.MessageSource;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.support.GenericMessage;

@SpringBootApplication
@EnableBinding(PolledConsumer.class)
public class Pollable {
    int count;

    public static void main(String[] args) {
        SpringApplication.run(Pollable.class, args);
    }

    @Bean
    public ApplicationRunner poller(PollableMessageSource input, MessageChannel output) {
        return args -> {
            while (true) {
                try {
                    if (!input.poll(m -> {
                        String str = new String((byte[])m.getPayload());
                        String newPayload = str.toUpperCase();
                        output.send(new GenericMessage<>(newPayload));
                    })) {
                        Thread.sleep(1000);
                    }
                } catch (Exception e) {
                    // handle failure (throw an exception to reject the message);
                }
            }
        };
    }
}

interface PolledConsumer {
    @Input
    PollableMessageSource input();

    @Output
    MessageChannel output();
}