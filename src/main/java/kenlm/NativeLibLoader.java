package kenlm;

import java.io.*;

class NativeLibLoader {

    /**
     * Create a temp file that copies the resource from current JAR archive
     * <p/>
     * The file from JAR is copied into system temp file.
     * The temporary file is deleted after exiting.
     * Method uses String as filename because the pathname is "abstract", not system-dependent.
     * <p/>
     * The restrictions of {@link File#createTempFile(java.lang.String, java.lang.String)} apply to
     * {@code path}.
     * @param path Path to the resources in the jar
     * @return The created temp file.
     * @throws IOException When the temp file could