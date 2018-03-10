package domain.statements;

import domain.FileData;
import domain.IFileTable;
import domain.PrgState;
import domain.expressions.Expression;
import domain.statements.Statement;
import exceptions.InterpretorException;
import utils.IHeap;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements Statement {
    private Expression expFileId;
    private String varName;

    public ReadFile(Expression ef,String vn){
        expFileId = ef;
        varName = vn;
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
    public PrgState execute(PrgState p){
        IHeap<Integer,Integer> h = p.getHeap();

        int value = expFileId.eval(p.getSymbols(),h);
        if(!exists(p,value))
            throw new InterpretorException("File not found");
        try {
            BufferedReader buff = p.getFileTable().get(value).getFileDescriptor();
            String line = buff.readLine();
            //System.out.println(line);
            int i;
            if (line.equals(null))
                i = 0;
            else
                i = Integer.parseInt(line);
            if(p.getSymbols().contains(varName))
                p.getSymbols().update(varName,i);
            else
                p.getSymbols().add(varName,i);
        }catch(IOException ioe){
            throw new InterpretorException(ioe.getMessage());
        }
        return null;
    }

    @Override
    public String toString(){
        return "readFile("+expFileId+","+varName+")";
    }
}
