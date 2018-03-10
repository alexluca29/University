package domain.expressions;

import utils.IDictionary;
import utils.IHeap;

public class NegExpr implements Expression {
    Expression e;

    public NegExpr(Expression expr){
        e = expr;
    }

    @Override
    public int eval(IDictionary<String,Integer> symbolTable, IHeap<Integer,Integer> heap){
        if (e.eval(symbolTable,heap) == 1)
            return 0;
        return 1;
    }

    @Override
    public String toString(){
        return "!"+e;
    }
}
