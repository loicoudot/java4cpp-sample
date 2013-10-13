package java4cpp.demos;

import java.io.IOException;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Sample class to demonstrate exception handling with java4cpp.
 */
@Java4Cpp
public class ExceptionClass {

    public void someMethod() {
    }

    /**
     * Return a null instance of ExceptionClass
     * 
     * @return a null instance
     */
    public static ExceptionClass getNullInstance() {
        return null;
    }

    /**
     * This method generate a NullPointerException by calling a method on a null
     * instance class
     */
    public static void generateNullPointerException() {
        ExceptionClass nullInstance = getNullInstance();
        nullInstance.someMethod();
    }

    /**
     * This method generate an unchecked exception
     */
    public static void generateUncheckedException() {
        @SuppressWarnings("unused")
        int val = 12 / 0;
    }

    /**
     * This method generate a checked exception
     * 
     * @throws IOException
     */
    public static void generateCheckedException() throws IOException {
        throw new IOException("Checked exception launched from Java");
    }

    /**
     * This method generate a custom checked exception
     * 
     * @throws CheckedException
     */
    public static void generateCustomCheckedException() throws CheckedException {
        throw new CheckedException("Custom checked exception launched from Java");
    }

    /**
     * This method generate a custom checked exception
     */
    public static void generateCustomUncheckedException() {
        throw new UncheckedException("Custom unchecked exception launched from Java");
    }
}
