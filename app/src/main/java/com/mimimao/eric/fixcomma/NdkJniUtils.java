package com.mimimao.eric.fixcomma;

/**
 * Created by eric on 2015/9/28.
 */
public class NdkJniUtils {
    static {
        System.loadLibrary("JFixCommA");	//defaultConfig.ndk.moduleName
    }
    public native String getCLanguageString();
}
