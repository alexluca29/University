package domain.expressions;

import exceptions.DivisionException;
import utils.IDictionary;
import utils.IHeap;

public class ArithmeticExpression implements Expression {
    private  char operator;
    private Expression left,right;

    public ArithmeticExpression(char op,Expression left,Expression right){
        this.operator = op;
        this.left = left;
        this.right = right;
    }

    @Override
    public int eval(IDictionary<String,Integer> symTable, IHeap<Integer,Integer> heap) {
        int left1 = left.eval(symTable,heap);
        int right1 = right.eval(symTable,heap);
        if (operator == '+')
            return left1 + right1;
        if (operator == '-')
            return left1 - right1;
        if (operator == '*')
            return left1 * right1;
        if (operator == '/')
            if (right1 == 0)
                throw new DivisionException("Division by zero");
            return left1 / right1;
    }

    @Override
    public String toString(){
        return left.toString()+operator+right.toString();
    }
}
