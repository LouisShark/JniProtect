package ilouis.me.jniprotect;

/**
 * Created by LouisShark on 2017/9/7.
 * this is on ilouis.me.jniprotect.
 */

public class Watcher {



    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native void watch(int userId);


}
