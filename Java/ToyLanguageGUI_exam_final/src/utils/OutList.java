package utils;

import java.util.ArrayList;
import java.util.List;

public class OutList<T> implements IOutList<T> {
    private List<T> l;
    public OutList(){
        l = new ArrayList<>();
    }


    public void addMsg(T m){
        l.add(m);
    }

    @Override
    public String toString(){
        StringBuffer buff = new StringBuffer();
        for(T e : l)
            buff.append(""+e+"\n");
        return buff.toString();
    }

    @Override
    public Iterable<T> getAll(){
        return l;
    }
}
