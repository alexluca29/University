package domain.statements;

import domain.PrgState;
import domain.expressions.Expression;
import exceptions.InterpretorException;
import utils.IDictionary;
import utils.IHeap;

public class wH implements Statement {
    private String var;
    private Expression expr;

    public wH(String v,Expression e){
        var = v;
        expr = e;
    }

    @Override
    public PrgState execute(PrgState p){
        IHeap<Integer,Integer> h = p.getHeap();
        IDictionary<String,Integer> sym = p.getSymbols();
        int expRes = expr.eval(sym,h);
        if(!sym.contains(var))
            throw new InterpretorException("the variable could not be found in the symbol table");
        int addr = sym.get(var);
        if (!h.contains(addr))
            throw new InterpretorException("heap location not allocated");
        h.update(addr,expRes);

        return null;
    }

    @Override
    public String toString(){
        return "wH("+var+","+expr+")";
    }

}
