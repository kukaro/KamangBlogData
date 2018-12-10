package com.company;

import org.objectweb.asm.*;

import java.io.FileOutputStream;
import java.io.IOException;

public class StringTransformer implements Opcodes {
    public void transform(String className) throws IOException {
        ClassReader reader = new ClassReader("java.lang." + className);
        ClassWriter writer = new ClassWriter(ClassWriter.COMPUTE_MAXS);
        ClassAdapter adapter = new StringClassAdapter(writer);
        reader.accept(adapter, ClassReader.SKIP_FRAMES);

        byte[] b = writer.toByteArray();
        FileOutputStream fos = new FileOutputStream(className + ".class");
        fos.write(b);
        fos.flush();
    }

    public static void main(String[] args) {
        try {
            String className = "String";
            StringTransformer fit = new StringTransformer();
            fit.transform(className);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
