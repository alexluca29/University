package domain.statements;

import domain.*;
import exceptions.InterpretorException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class OpenRFile implements Statement {
    private String varFile;
    private String nameFile;
    public OpenRFile(String vf,String nf){
        varFile = vf;
        nameFile = nf;
    }

    private boolean exists(PrgState p, String fn){
        IFileTable<Integer,FileData> ft = p.getFileTable();
        for(FileData key : ft.getValues())
        {
            if(key.getFilename().equals(fn))
                    return true;
        }
        return false;
    }

    @Override
    public PrgState execute(PrgState p){
        if(exists(p,nameFile))
            throw new InterpretorException("File already open");
        try{
            BufferedReader buff = new BufferedReader(new FileReader(nameFile));
            FileData fd = new FileData(nameFile,buff);
            int id = IDGenerator.generateID();
            p.getFileTable().add(id,fd);
            if(p.getSymbols().contains(varFile))
                p.getSymbols().update(varFile,id);
            else
                p.getSymbols().add(varFile,id);
        }catch(IOException ioe){
            throw new InterpretorException(ioe.getMessage());
        }
        return null;
    }

    @Override
    public String toString(){
        return "openFile("+varFile+","+nameFile+")";
    }

}
