package repository;

import domain.PrgState;

import java.util.List;

public interface IRepository {
    void addPrgState(PrgState p);
    void logProgStateExec(PrgState p);
    List<PrgState> getPrgList();
    void setPrgList(List<PrgState> l);
}
