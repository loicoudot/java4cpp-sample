package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Demonstration of custom checked exception.
 */
@Java4Cpp
public class CheckedException extends Exception {

    public CheckedException(String string) {
        super(string);
    }

    private static final long serialVersionUID = 1L;

}
