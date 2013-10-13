package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Sample base class to demonstrate {@code superclass} attribute.
 */
class Baseclass {
    public Baseclass() {
    }

    public int baseMethod() {
        return 1;
    }

    public int overridenMethod() {
        return 2;
    }
}

/**
 * A class that extends {@code Baseclass}. The attribute {@code superclass} is
 * true, so the C++ proxy of {@code Superclass} also inherit of the C++ proxy of
 * {@code Baseclass}.
 */
@Java4Cpp(superclass = true)
public class Superclass extends Baseclass {

    /**
     * Like {@code Superclass} but this time with an inner-class.
     */
    @Java4Cpp(superclass = true)
    public static class WithSuperclass extends Baseclass {

        @Override
        public int overridenMethod() {
            return 4;
        }
    }

    /**
     * As {@code superclass} is false, the C++ proxy of
     * {@code WithoutSuperClass} won't inherit of the {@code WithSuperClass} C++
     * proxy's.
     */
    @Java4Cpp(superclass = false)
    public static class WithoutSuperclass extends WithSuperclass {
        @Override
        public int overridenMethod() {
            return 5;
        }
    }

    @Override
    public int overridenMethod() {
        return 3;
    }
}
