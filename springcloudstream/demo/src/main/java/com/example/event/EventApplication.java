//https://engkimbs.tistory.com/718
package com.example.event;

import com.example.demo.TestSink;
import com.example.loggingconsumer.Person;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.context.ApplicationContext;


@SpringBootApplication
@EnableBinding(Processor.class)
public class EventApplication {

	@Autowired
	ApplicationContext applicationContext;

	public static void main(String[] args) {
		SpringApplication.run(EventApplication.class,args);
	}

	@StreamListener(Processor.INPUT)
	public void handler(String person){
		applicationContext.publishEvent(new MyEvent(person));
	}
}

class MyEvent{
	public String data;

	public MyEvent(String data) {
		this.data = data;
	}

	@Override
	public String toString() {
		return "MyEvent{" +
				"data='" + data + '\'' +
				'}';
	}
}