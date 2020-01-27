package com.example.mytest;

import com.example.demo.TestSink;
import com.example.event.EventApplication;
import com.example.loggingconsumer.LoggingConsumerApplication;
import static org.junit.Assert.*;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.cloud.stream.test.binder.MessageCollector;
import org.springframework.messaging.Message;
import org.springframework.messaging.support.GenericMessage;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest(classes = LoggingConsumerApplication.class)
class MyTests {

	@Autowired
	private Processor processor;

	@Autowired
	private MessageCollector messageCollector;

	@Test
	void contextLoads() {
		Message<String> message = new GenericMessage<>("hello");
		processor.input().send(message);
		Message<String> received = (Message<String>)messageCollector.forChannel(processor.output()).poll();
		assertEquals(received.getPayload(),"!!hello!!");
	}

}
