package java4cpp.demos;

import com.github.loicoudot.java4cpp.Java4Cpp;

@Java4Cpp
public class Threads {

    private long iter = 0;

    public Threads() {
    }

    synchronized public void threadsafe() {
        iter = iter + 1;
    }

    public long getIter() {
        return iter;
    }
}
