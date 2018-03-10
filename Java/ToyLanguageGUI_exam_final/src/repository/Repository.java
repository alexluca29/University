package repository;

import domain.*;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

import domain.statements.Statement;
import exceptions.*;


public class Repository implements IRepository {
    private List<PrgState> a;
    private String logFile;

    public Repository(String fileName){
        logFile = fileName;
        a = new ArrayList<>();
    }

    public void addPrgState(PrgState p){
        a.add(p);
    }


    public void logProgStateExec(PrgState p){
        try(PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(logFile,true)));
        ){

            pw.println("\n ID:"+p.getId()+"\n");
            pw.println("------------------");
            pw.println("ExeStack: ");
            PrgState current = p;
            for(Statement s:current.getStack().getAll())
                pw.println(s);
            pw.println("\n");
            pw.println("SymTable: ");
            for(String s : current.getSymbols().getAll()) {
                    int val = current.getSymbols().get(s);
                    pw.println(s + "->" + val);
            }
            pw.println("\n");
            pw.println("Out: ");
            for(Integer i : current.getMessages().getAll())
                pw.println(i);
            pw.println("\n");
            pw.println("FileTable: ");
            for(Integer i : current.getFileTable().getAll()) {
                FileData val = current.getFileTable().get(i);
                pw.println(i + "->" +val);
            }
            pw.println("\n");
            pw.println("Heap: ");
            for(Integer k : current.getHeap().getAll()){
                int val = current.getHeap().get(k);
                pw.println(k + "->" + val);
            }
        }
        catch(IOException ioe){
            throw new InterpretorException(ioe.getMessage());
        }
    }

    public List<PrgState> getPrgList(){
        return a;
    }

    public void setPrgList(List<PrgState> l){
        a = l;
    }
}


