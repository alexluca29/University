package domain.statements;

import domain.FileData;
import domain.FileTable;
import domain.IFileTable;
import domain.PrgState;
import utils.*;
import domain.expressions.Expression;

public class WhileStmt implements Statement {
    private Expression e;
    private Statement s;
    public WhileStmt(Expression expr,Statement stmt){
        e = expr;
        s = stmt;
    }

    @Override
    public PrgState execute(PrgState p){
        IDictionary<String, Integer> sym = p.getSymbols();
        IHeap<Integer,Integer> heap = p.getHeap();
        if (e.eval(sym,heap) != 0) {
            p.getStack().push(this);
            p.getStack().push(s);
        }
        return null;
    }

    @Override
    public String toString(){
        return "while("+e+")"+"{\n"+s.toString()+"}";
    }
}
