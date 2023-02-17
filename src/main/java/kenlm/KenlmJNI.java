package kenlm;

import java.io.IOException;

class KenlmJNI {

    static {
        try {
            System.load(NativeLibLoader.createTempFileFromResource("/" + System.mapLibraryName("kenlm_jni")));
        } catch (IOException e) {
            throw new UnsatisfiedLinkError(e.getMessage())