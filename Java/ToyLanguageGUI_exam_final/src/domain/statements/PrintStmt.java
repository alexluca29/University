package domain.statements;

import domain.PrgState;
import domain.expressions.Expression;
import utils.IDictionary;
import utils.IHeap;
import utils.IOutList;

public class PrintStmt implements Statement {
    private Expression expr;
    public PrintStmt(Expression e)
    {
        expr = e;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        //try {
            IOutList<Integer> list = p.getMessages();
            IDictionary<String, Integer> dict = p.getSymbols();
            IHeap<Integer,Integer> h = p.getHeap();

            int res = expr.eval(dict,h);
            list.addMsg(res);
        //}
        //catch(StackException se){
         //   System.out.println(se.getMessage());}
        return null;
    }

    @Override
    public String toString()
    {
        return "print(" + expr + ")";
    }
}
