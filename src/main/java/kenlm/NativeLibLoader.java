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
     * @throws IOException When the temp file could not be created
     * @throws IllegalArgumentException When the file name contains invalid letters
     */
    static String createTempFileFromResource(String path) throws IOException, IllegalArgumentException {
        // Obtain filename from path
        if (!path.startsWith("/")) {
            throw new IllegalArgumentException("The path has to be absolute (start with '/').");
        }

        String[] parts = path.split("/");
        String filename = (parts.length > 1) ? parts[parts.length - 1] : null;

        // Split filename to prexif and suffix (extension)
        String prefix = "";
        String suffix = null;
        if (filename != null) {
            parts = filename.split("\\.", 2);
            prefix = parts[0];
            suffix = (parts.length > 1) ? "." + parts[parts.length - 1] : null; // Thanks, davs! :-)
        }

        // Check if the filename is okay
        if (filename == null || prefix.length() < 3) {
            throw new IllegalArgumentException("The filename has to be at least 3 characters long.");
        }
        // Prepare temporary file
        File temp = File.createTempFile(prefix, suffix);
        temp.deleteOnExit();

        if (!temp.exists()) {
            throw new FileNotFoundException("File " + 