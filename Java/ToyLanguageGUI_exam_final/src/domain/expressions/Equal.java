package domain.expressions;

import utils.IDictionary;
import utils.IHeap;

public class Equal implements Expression {
    private Expression e1;
    private Expression e2;

    public Equal(Expression exp1,Expression exp2){
        e1 = exp1;
        e2 = exp2;
    }

    @Override
    public int eval(IDictionary<String,Integer> sym, IHeap<Integer,Integer> h){
        int ev1 = e1.eval(sym,h);
        int ev2 = e2.eval(sym,h);

        if (ev1 == ev2)
            return 1;
        else
            return 0;
    }

    @Override
    public String toString(){
        return ""+e1+"=="+e2;
    }
}
