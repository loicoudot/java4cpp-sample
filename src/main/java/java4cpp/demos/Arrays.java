package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class Arrays {

    public long[] negate(int[] in) {
        long[] result = new long[in.length];
        for (int i = 0; i < in.length; ++i) {
            result[i] = -in[i];
        }
        return result;
    }

    public boolean[] invert(boolean[] in) {
        boolean[] result = new boolean[in.length];
        for (int i = 0; i < in.length; ++i) {
            result[i] = !in[i];
        }
        return result;
    }

    public double[] add(float[] in) {
        double[] result = new double[in.length];
        for (int i = 0; i < in.length; ++i) {
            result[i] = in[i] + 0.5;
        }
        return result;
    }

    public Double[] add(Float[] in) {
        Double[] result = new Double[in.length + 1];
        for (int i = 0; i < in.length; ++i) {
            result[i] = in[i] + 0.5;
        }
        result[in.length] = null;
        return result;
    }

    public float[][] identity(float[][] in) {
        return in;
    }
}
