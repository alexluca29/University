package domain.expressions;

import utils.IDictionary;
import utils.IHeap;

public class ConstExpression implements Expression {
    private int constant;
    public ConstExpression(int value){
        constant = value;
    }

    @Override
    public int eval(IDictionary<String,Integer> symbTable, IHeap<Integer,Integer> heap){
        return constant;
    }

    @Override
    public String toString(){
        return "" + constant;
    }
}
