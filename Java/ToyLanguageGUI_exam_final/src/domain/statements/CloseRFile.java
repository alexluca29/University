package domain.statements;

import domain.*;
import domain.expressions.Expression;
import exceptions.InterpretorException;
import utils.IHeap;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseRFile implements Statement {
    private Expression expFile;
    public CloseRFile(Expression ef){
        expFile = ef;
    }


    public boolean exists(PrgState p, int i)
    {
        IFileTable<Integer,FileData> ft = p.getFileTable();
        for(FileData key : ft.getValues())
        {
            if(key.getFileDescriptor() != null)
                return true;
        }
        return false;
    }

    @Override
    public PrgState execute(PrgState p) {
        try {
            IHeap<Integer,Integer> h = p.getHeap();

            int value = expFile.eval(p.getSymbols(),h);
            if(!exists(p,value))
                throw new InterpretorException("File not found");
            BufferedReader buff = p.getFileTable().get(value).getFileDescriptor();

            buff.close();

            p.getFileTable().remove(value);
        }catch(IOException ioe){
            throw new InterpretorException(ioe.getMessage());
        }catch(RuntimeException e){
            System.out.println(e.getMessage());
        }


        return null;
    }

    @Override
    public String toString(){
        return "closeFile("+expFile+")";
    }
}
