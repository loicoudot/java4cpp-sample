package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Demonstration of custom unchecked exception.
 */
@Java4Cpp
public class UncheckedException extends RuntimeException {

    public UncheckedException(String string) {
        super(string);
    }

    private static final long serialVersionUID = 1L;

}
