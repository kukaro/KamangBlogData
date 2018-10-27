package net.theceres.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HelloWorldController {
    private String hello = "Hello";

    @RequestMapping("/hello")
    public ModelAndView showMessage(@RequestParam(value = "name", required = false, defaultValue = "World") String name) {
        System.out.println("hello world controller");
        ModelAndView mv = new ModelAndView("helloworld");
        mv.addObject("hello", hello);
        mv.addObject("name", name);
        return mv;
    }

}
