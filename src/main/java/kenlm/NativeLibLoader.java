package kenlm;

import java.io.*;

class NativeLibLoader {

    /**
     * Create a temp file that copies the resource from current JAR archive
     * <p/>
     * The file from JAR is copied into system temp file.
     * The temporary file is deleted after exiting.
     * Me