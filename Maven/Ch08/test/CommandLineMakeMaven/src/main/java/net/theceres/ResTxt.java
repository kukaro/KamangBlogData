package net.theceres;

import java.util.ResourceBundle;

public class ResTxt {
    private final static String RESOURCE = "main";
    private static final ResourceBundle RESOURCE_BUNDLE = ResourceBundle.getBundle(RESOURCE);

    public static String getS(String key) {
        return RESOURCE_BUNDLE.getString(key);
    }
}