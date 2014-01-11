package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class InnerClass {

    public static class InnerInnerClass {

        public Double method(InnerEnumeration.Enumeration in) {
            return 2.0;
        }

    }

    public Short method(Short A) {
        return A;
    }

    public void method(Superclass.WithoutSuperclass A) {
    }
}
