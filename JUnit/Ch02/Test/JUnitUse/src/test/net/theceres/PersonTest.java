package net.theceres;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PersonTest {
    @Test
    @DisplayName("Person's nameDecorate method's test")
    void nameDecorate() {
        Person p = new Person("kukaro", 26);
        assertEquals("kukarogood", p.nameDecorate("good"), "fail");
    }

    @Test
    void isMatchAge() {
        Person p = new Person("kukaro", 26);
        assertNotNull(p, "is null");
    }

}
