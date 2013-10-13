package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

/**
 * Sample class to demonstrate allocation, copy, clone.
 */
@Java4Cpp
public class Allocation implements Cloneable {

    private int value = -1;

    public Allocation() {
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    protected Allocation clone() throws CloneNotSupportedException {
        return (Allocation) super.clone();
    }
}
