package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class InnerEnumeration {

    public static Enumeration enumAsParameter(Enumeration a, Enumeration b) {
        return Enumeration.THREE;
    }

    public enum Enumeration {
        ONE, TWO, THREE;
    }
}
