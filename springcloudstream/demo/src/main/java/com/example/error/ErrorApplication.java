package com.example.error;

import com.example.loggingconsumer.Person;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.integration.annotation.ServiceActivator;
import org.springframework.messaging.Message;

@SpringBootApplication
@EnableBinding(Sink.class)
public class ErrorApplication {
	public static void main(String[] args) {
		SpringApplication.run(ErrorApplication.class,args);
	}

	@StreamListener(Sink.INPUT)
	public void handler(Person person){
		System.out.println("Received : " + person);
		throw new RuntimeException("BOOM!");
	}

	@ServiceActivator(inputChannel = "test.mygroup.errors") //channel name 'input.myGroup.errors'
	public void error(Message<?> message) {
		System.out.println("Handling ERROR: " + message);
	}
}
