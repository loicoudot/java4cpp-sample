package java4cpp.demos;

import java.util.ArrayList;
import java.util.List;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class Containers {

    public List<Double> listObject() {
        List<Double> result = new ArrayList<Double>();
        result.add(2.5);
        result.add(4.6);
        result.add(7.8);
        return result;
    }

    public List<String> listConvertible() {
        return new ArrayList<String>();
    }
}
