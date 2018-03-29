package net.theceres;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PersonTest {
    @Test
    @DisplayName("Persons info test")
    void toInfo() {
        Person p = new Person("kukaro", 26);
        assertEquals("(name:kukaro,age:26)", p.toInfo());
    }
}