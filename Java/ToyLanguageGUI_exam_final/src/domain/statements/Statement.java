package domain.statements;

import domain.PrgState;

public interface Statement {
    PrgState execute(PrgState p);
}