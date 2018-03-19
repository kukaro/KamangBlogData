package net.theceres;

public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String nameDecorate(String str) {
        return this.name + str;
    }

    public boolean isMatchAge(int age) {
        return this.age == age;
    }
}
