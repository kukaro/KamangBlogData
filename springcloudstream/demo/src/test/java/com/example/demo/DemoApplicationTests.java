package com.example.demo;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringBootConfiguration;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.stream.messaging.Sink;

@SpringBootTest(classes = DemoApplication.class)
class DemoApplicationTests {

	@Autowired
	private TestSink sink;

	@Test
	void contextLoads() {
		System.out.println(sink.inputs());
		assert(sink!=null);
	}

}
