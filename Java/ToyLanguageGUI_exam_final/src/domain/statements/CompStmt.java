package domain.statements;

import domain.PrgState;
import utils.IExecStack;

public class CompStmt implements Statement {
    private Statement s1;
    private Statement s2;
    public CompStmt(Statement s1,Statement s2){
        this.s1 = s1;
        this.s2 = s2;
    }

    @Override
    public PrgState execute(PrgState p){
        //try{
        IExecStack<Statement> stack = p.getStack();
        stack.push(s2);
        stack.push(s1);
       // }catch (StackException se){
        //    System.out.println(se.getMessage());}
        return null;
    }

    @Override
    public String toString(){
        return s1.toString() +"\n"+ s2.toString();
    }
}
