package domain.expressions;

import exceptions.InterpretorException;
import utils.IDictionary;
import utils.IHeap;

public class rH implements Expression {
    private String var;

    public rH(String v){
        var = v;
    }

    @Override
    public int eval(IDictionary<String,Integer> sym,IHeap<Integer,Integer> h){
        if (!sym.contains(var))
            throw new InterpretorException("the variable could not be found in the symbol table");
        int v = sym.get(var);
        if (!h.contains(v))
            throw new InterpretorException("heap location not allocated");
        return h.get(v);
    }

    @Override
    public String toString(){
        return "readH("+var+")";
    }
}
