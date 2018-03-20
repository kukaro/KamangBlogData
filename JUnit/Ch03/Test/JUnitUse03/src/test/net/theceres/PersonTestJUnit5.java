package net.theceres;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PersonTestJUnit5 {
    @Test
    public void test1() {
        Person p = new Person("kukaro", 26);
        assertAll(
                () -> assertEquals("kukarogood", p.nameDecorate("god"), "equal not matching"),
                () -> assertSame(p, new Person("kukaro", 26), "same nt matching")
        );
    }

    @Test
    public void test2() {
        Person p = new Person("kukaro", 26);
        assertEquals("kukarogood", p.nameDecorate("god"), "equal not matching");
        assertSame(p, new Person("kukaro", 26), "same nt matching");
    }

}
