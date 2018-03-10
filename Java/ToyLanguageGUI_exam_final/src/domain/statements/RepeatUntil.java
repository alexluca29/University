package domain.statements;

import domain.PrgState;
import domain.expressions.Expression;
import domain.expressions.NegExpr;

public class RepeatUntil implements Statement {
    Statement stmt;
    Expression exp2;

    public RepeatUntil(Statement s,Expression e){
        stmt = s;
        exp2 = e;
    }

    @Override
    public PrgState execute(PrgState p){
        Statement newStmt = new CompStmt(stmt, new WhileStmt( new NegExpr(exp2),stmt));
        p.getStack().push(newStmt);
        return null;
    }

    @Override
    public String toString(){
        return "repeat("+stmt+")\n until "+exp2+")";
    }
}
