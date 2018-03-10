package domain.statements;

import domain.PrgState;
import exceptions.InterpretorException;

public class Await implements Statement {
    String var;

    public Await(String v){
        var = v;
    }

    @Override
    public PrgState execute(PrgState p){
        if (!p.getSymbols().contains(var))
            throw new InterpretorException("Variable not in symbol table");
        int id = p.getSymbols().get(var);
        if (!p.getLatchTable().contains(id))
            throw new InterpretorException("Id not in Latch table");
        synchronized (p.getLatchTable()){
            if (p.getLatchTable().get(id) != 0)
                p.getStack().push(this);
        }

        return null;

    }

    @Override
    public String toString(){
        return "await("+var+")";
    }
}
