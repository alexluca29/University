package domain.statements;

import domain.expressions.Expression;
import domain.PrgState;
import utils.IDictionary;
import utils.IHeap;

public class AssignStmt implements Statement {
    private String varName;
    private Expression expr;

    public AssignStmt(String v,Expression e)
    {
        this.varName = v;
        this.expr = e;
    }

    @Override
    public PrgState execute(PrgState p){
        //try {
            IDictionary<String, Integer> symb = p.getSymbols();
            IHeap<Integer,Integer> h = p.getHeap();
            int result = expr.eval(symb,h);
            if (symb.contains(varName))
                symb.update(varName, result);
            else
                symb.add(varName, result);
        //}catch (StackException se){
        //System.out.println(se.getMessage());}
        return null;
    }

    @Override
    public String toString(){
        return varName + '=' +expr;
    }
}
