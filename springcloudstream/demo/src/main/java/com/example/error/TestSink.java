package com.example.error;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.messaging.SubscribableChannel;

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
