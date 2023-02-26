package kenlm;

import java.io.IOException;

class KenlmJNI {

    static {
        try {
            System.load(NativeLibLoader.createTempFileFromResource("/" + System.mapLibraryName("kenlm_jni")));
        } catch (IOException e) {
            throw new UnsatisfiedLinkError(e.getMessage());
        }
    }

    static native long ConfigNew();
    static native void ConfigDelete(long c);
    static native int ConfigGetLoadMethod(long c);
    static native void ConfigSetLoadMethod(long c, int load_method);

    static native long ModelLoadVirtual(String path, long config);
    static native void ModelDelete(long model);

   