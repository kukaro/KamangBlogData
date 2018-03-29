package net.theceres;

public class Person {
    String name;
    int age;

    public Person(String name,int age){
        this.name = name;
        this.age = age;
    }

    public String toInfo() {
        return "(name:"+ name +",age:"+age+")";
    }
}
