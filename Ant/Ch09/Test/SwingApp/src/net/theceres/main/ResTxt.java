package net.theceres.main;

import java.util.ResourceBundle;

public class ResTxt {
    private final static String RESOURCE = "resource.text.main";
    private static final ResourceBundle RESOURCE_BUNDLE = ResourceBundle.getBundle(RESOURCE);

    public static String getS(String key) {
        return RESOURCE_BUNDLE.getString(key);
    }
}