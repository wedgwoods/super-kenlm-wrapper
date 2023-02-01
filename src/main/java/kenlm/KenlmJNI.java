package kenlm;

import java.io.IOException;

class KenlmJNI {

    static {
        try {
            System.load(NativeLibLoader.createTempFileFro