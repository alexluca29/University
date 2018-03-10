package domain.statements;

import domain.IDGenerator;
import domain.PrgState;
import domain.expressions.Expression;
import utils.IDictionary;

public class NewLatch implements Statement {
    String var;
    Expression e;

    public NewLatch(String v,Expression expr){
        var = v;
        e = expr;
    }

    @Override
    public PrgState execute(PrgState p){

        int number;
        number = e.eval(p.getSymbols(),p.getHeap());
        int id;
        synchronized (p.getLatchTable()){
            id = IDGenerator.generateID();
            p.getLatchTable().add(id,number);
        }
        IDictionary<String,Integer> st = p.getSymbols();
        if (p.getSymbols().contains(var))
            st.update(var,id);
        else
            st.add(var,id);

        return null;
    }

    @Override
    public String toString(){
        return "newLatch("+var+","+e+")";
    }
}
