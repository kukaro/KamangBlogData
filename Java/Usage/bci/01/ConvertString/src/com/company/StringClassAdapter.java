package com.company;

import org.objectweb.asm.ClassAdapter;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.MethodVisitor;

public class StringClassAdapter extends ClassAdapter {
    public StringClassAdapter(ClassVisitor visitor) {
        super(visitor);
    }
    public MethodVisitor visitMethod(int access, String name, String desc, String sig, String[] exes) {
        MethodVisitor mv = super.visitMethod(access, name, desc, sig, exes);

        System.out.println("StringClassAdapter.visitMethod");
        System.out.println("access = [" + access + "], name = [" + name + "], desc = [" + desc + "]," +
                "sig = [" + sig + "], exes = [" + exes + "]");

        return mv;

    }
}
