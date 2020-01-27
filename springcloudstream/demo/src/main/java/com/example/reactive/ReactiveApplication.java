package com.example.reactive;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Processor;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.context.annotation.Bean;
import reactor.core.publisher.Flux;

import java.time.Duration;
import java.util.function.Function;

@SpringBootApplication
//@EnableBinding(Processor.class)
public class ReactiveApplication {
    public static void main(String[] args) {
        SpringApplication.run(ReactiveApplication.class, args);
    }

    @Bean
    public Function<Flux<String>, Flux<String>> aggregate() {
        return inbound -> inbound.
                log()
                .window(Duration.ofSeconds(30), Duration.ofSeconds(5))
                .flatMap(w -> {
                    System.out.println(w + "!!");
                    System.out.println(Thread.currentThread());
                    return w.reduce("", (s1, s2) -> {
                        System.out.println(s1 + "!!" + s2);
                        return s1 + s2;
                    });
                })
                .log();
    }
}
