package domain.expressions;

import utils.IDictionary;
import utils.IHeap;

public interface Expression {
    int eval(IDictionary<String,Integer> symbolTable, IHeap<Integer,Integer> heap);
}
