package domain.expressions;


import domain.expressions.Expression;
import utils.IDictionary;
import utils.IHeap;

public class VarExpression implements Expression {
    private String varName;
    public VarExpression(String varName){
        this.varName = varName;
    }

    @Override
    public int eval(IDictionary<String,Integer> symbTable, IHeap<Integer,Integer> heap) throws RuntimeException{
        if(symbTable.contains(varName))
            return symbTable.get(varName);
        throw new RuntimeException("Not found");
    }

    @Override
    public String toString(){
        return varName;
    }

}
