package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public enum Enumeration {
    ONE(10), TWO(20), THREE(30);

    private int value;

    Enumeration(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}