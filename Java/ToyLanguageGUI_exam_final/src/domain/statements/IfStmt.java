package domain.statements;

import domain.PrgState;
import domain.expressions.Expression;
import utils.IDictionary;
import utils.IExecStack;
import utils.IHeap;

public class IfStmt implements Statement {
    private Expression condition;
    private Statement TrueS,FalseS;
    public IfStmt(Expression e,Statement s1,Statement s2){
        this.condition = e;
        this.TrueS = s1;
        this.FalseS = s2;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        //try {
            IExecStack<Statement> s = p.getStack();
            IDictionary<String, Integer> st = p.getSymbols();
            IHeap<Integer,Integer> h = p.getHeap();
            if (this.condition.eval(st,h) == 0)
                s.push(this.TrueS);
            else
                s.push(this.FalseS);
        //}catch(StackException se){
         //   System.out.println(se.getMessage());}
        return null;
    }

    @Override
    public String toString(){
        return "if(" + condition + ") then " + TrueS + " else " + FalseS;
    }


}
