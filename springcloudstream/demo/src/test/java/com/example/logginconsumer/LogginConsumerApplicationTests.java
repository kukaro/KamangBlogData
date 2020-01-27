package com.example.logginconsumer;

import com.example.demo.TestSink;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.stream.messaging.Sink;

@SpringBootTest
class LogginConsumerApplicationTests {

	@Autowired
	private Sink sink;

	@Test
	void contextLoads() {
		System.out.println(sink);
	}

}
