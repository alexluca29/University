package domain.statements;
import domain.IDGenerator;
import domain.expressions.Expression;
import  domain.PrgState;
import utils.*;

public class newH implements Statement {
    private String var;
    private Expression expr;

    public newH(String v,Expression e){
        var = v;
        expr = e;
    }

    @Override
    public PrgState execute(PrgState p) {
        IHeap<Integer,Integer> h = p.getHeap();
        IDictionary<String,Integer> sym = p.getSymbols();

        int expRes = expr.eval(sym,h);
        int addr = IDGenerator.generateID();
        if (addr == 0)
            addr = IDGenerator.generateID();
        h.add(addr,expRes);
        if (sym.contains(var))
            sym.update(var,addr);
        else
            sym.add(var,addr);

        return null;
    }

    @Override
    public String toString(){
        return "new("+var+","+expr+")";
    }
}
