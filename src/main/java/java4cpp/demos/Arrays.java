package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class Arrays {

    public int[] negate(int[] in) {
        int[] result = new int[in.length];
        for (int i = 0; i < in.length; ++i) {
            result[i] = -in[i];
        }
        return result;
    }
}
