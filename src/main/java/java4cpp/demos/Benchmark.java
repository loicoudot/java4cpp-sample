package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Sample class to benchmark the performance of java4cpp.
 */
@Java4Cpp
public class Benchmark {

    public void noArgMethod() {
    }

    public long primitiveArgMethod(int a, double b) {
        return 3;
    }

    public Benchmark classArgMethod(Benchmark a) {
        return a;
    }
}
