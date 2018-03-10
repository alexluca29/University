package domain;

import domain.statements.Statement;
import utils.*;
import exceptions.StmtExecException;

public class PrgState {
    private int id;
    private IExecStack<Statement> exec;
    private IOutList<Integer> messages;
    private IDictionary<String,Integer> symbolT;
    private Statement stmt;
    private IFileTable fileTable;
    private IHeap heap;
    private ILatchTable<Integer,Integer> latchTable;
    public PrgState(IExecStack<Statement> stack,IOutList<Integer> messages,IDictionary<String,Integer> symbolT,Statement stmt,IFileTable<Integer,FileData> ft,IHeap h,ILatchTable<Integer,Integer> lt){
        id = IDGenerator.generateID();
        this.exec = stack;
        this.messages = messages;
        this.symbolT = symbolT;
        this.stmt = stmt;
        this.fileTable = ft;
        this.heap = h;
        this.latchTable = lt;
    }

    public int getId(){ return id; }

    public void setId(int ID){ id = ID; }

    public IExecStack<Statement> getStack(){
        return exec;
    }

    public IOutList<Integer> getMessages(){
        return messages;
    }

    public IDictionary<String,Integer> getSymbols(){
        return symbolT;
    }

    public Statement getStatement(){
        return stmt;
    }

    public IFileTable<Integer,FileData> getFileTable() {return fileTable;}

    public IHeap<Integer,Integer> getHeap() {return heap;}

    public ILatchTable<Integer,Integer> getLatchTable(){return latchTable;}

    @Override
    public String toString(){
        StringBuffer buff = new StringBuffer();
        buff.append("\n");
        buff.append(""+"ID:"+id+"\n");
        buff.append("--------------------\n");
        buff.append("Execution stack: \n");
        buff.append("" + exec + "\n");
        buff.append("Message list: \n");
        buff.append(messages + "\n");
        buff.append("Dictionary: \n");
        buff.append(""+symbolT + "\n" );
        buff.append("Statement: \n");
        buff.append(""+stmt +"\n");
        buff.append("File table: \n");
        buff.append(""+fileTable+"\n");
        buff.append("Heap: \n");
        buff.append(""+heap+"\n");
        buff.append("Latch table: \n");
        buff.append(""+latchTable+"\n");
        return buff.toString();
    }

    public Boolean isNotCompleted(){
        if (exec.isEmpty())
            return false;
        return true;
    }

    public PrgState oneStep(){
        if(getStack().isEmpty())
            throw new StmtExecException("Stack is empty");
        Statement stmt = getStack().pop();
        return stmt.execute(this);
    }

}
