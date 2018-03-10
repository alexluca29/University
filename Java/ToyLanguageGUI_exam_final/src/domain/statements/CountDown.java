package domain.statements;

import domain.PrgState;
import exceptions.InterpretorException;

public class CountDown implements Statement {
    String var;
    public CountDown(String v){
        var = v;
    }

    @Override
    public PrgState execute(PrgState p){
        if (!p.getSymbols().contains(var))
            throw new InterpretorException("Variable not in symbol table");

        int foundIndex = p.getSymbols().get(var);
        if (!p.getLatchTable().contains(foundIndex))
           // throw new InterpretorException("Id not found in Latch table");
            return null;
        synchronized (p.getLatchTable()){
            if (p.getLatchTable().get(foundIndex) > 0 ) {
                p.getLatchTable().update(foundIndex, p.getLatchTable().get(foundIndex) - 1);
                p.getMessages().addMsg(p.getId());
            }
        }

        return null;
    }

    @Override
    public String toString(){
        return "countDown("+var+")";
    }
}
