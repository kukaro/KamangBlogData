package KafkaProject.sub;

import org.springframework.stereotype.Component;

@Component
public class TestService {
    public void function(String a) {
        System.out.format("param : %s", a);
    }
}
