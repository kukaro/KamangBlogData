package net.theceres;

import org.junit.Test;

import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.core.IsNull.notNullValue;
import static org.junit.Assert.*;

public class PersonTestJUnit4 {
    @Test
    public void test1() throws Exception {
        Person p = new Person("kukaro", 26);
        assertThat("kuakro1",is(notNullValue()));
    }

    @Test
    public void test2() throws Exception {

    }

}