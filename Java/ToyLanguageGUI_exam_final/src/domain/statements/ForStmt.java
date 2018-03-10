package domain.statements;

import domain.PrgState;
import domain.expressions.Expression;

public class ForStmt implements Statement {
    Statement s1;
    Statement s2;
    Statement s3;
    Expression e;

    public ForStmt(Statement ex1,Expression ex2,Statement ex3,Statement st){
        s1 = ex1;
        e = ex2;
        s2 = ex3;
        s3 = st;
    }

    @Override
    public PrgState execute(PrgState p){
        Statement newStmt = new CompStmt(s1,new WhileStmt(e,new CompStmt(s3,s2)));
        p.getStack().push(newStmt);
        return null;

    }

    @Override
    public String toString(){
        return "for("+s1+";"+e+";"+s2+")"+s3;
    }

}
