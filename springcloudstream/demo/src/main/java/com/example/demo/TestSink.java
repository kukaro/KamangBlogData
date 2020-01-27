package com.example.demo;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.messaging.SubscribableChannel;
import org.springframework.stereotype.Component;

public interface TestSink {
    /**
     * Input channel name.
     */
    String INPUT = "inputs";

    /**
     * @return input channel.
     */
    @Input(TestSink.INPUT)
    SubscribableChannel inputs();

}
