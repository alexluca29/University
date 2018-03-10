package domain.statements;

import domain.FileData;
import domain.IFileTable;
import domain.PrgState;
import utils.*;


public class ForkStmt implements Statement {
    private Statement stmt;

    public ForkStmt(Statement s){
        stmt = s;
    }

    @Override
    public PrgState execute(PrgState p){
        IExecStack<Statement> newStack = new ExecStack<>();
        newStack.push(stmt);
        IDictionary<String,Integer> newTable = p.getSymbols().copy();
        IFileTable<Integer, FileData> ft = p.getFileTable();
        IHeap<Integer,Integer> heap = p.getHeap();
        IOutList<Integer> out = p.getMessages();
        ILatchTable<Integer,Integer> lt = p.getLatchTable();
        PrgState prSt = new PrgState(newStack,out,newTable,stmt,ft,heap,lt);
        prSt.setId(p.getId()*10);
        return prSt;
    }

    @Override
    public String toString(){
        return "fork("+stmt+")";
    }
}
