package net.theceres;

import org.junit.Test;

import static org.junit.Assert.*;

public class PersonTest {
    @Test
    public void nameDecorate() {
        Person p = new Person("kukaro", 26);
        assertEquals("fail","kukarogood", p.nameDecorate("good"));
    }

    @Test
    public void isMatchAge() {
        Person p = new Person("kukaro", 26);
        assertNotNull("fail",p);
    }

}
