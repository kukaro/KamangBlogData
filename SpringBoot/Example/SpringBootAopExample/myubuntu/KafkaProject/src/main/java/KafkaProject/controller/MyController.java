package KafkaProject.controller;

import KafkaProject.sub.TestService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MyController {

    TestService service;

    @Autowired
    MyController(TestService service){
        this.service = service;
    }

    @RequestMapping(value = "/", method = RequestMethod.GET)
    public String index(){
        service.function("good");
        return "hi";
    }
}
