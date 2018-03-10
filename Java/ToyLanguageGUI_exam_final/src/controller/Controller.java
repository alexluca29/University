package controller;

import domain.FileData;
import domain.PrgState;
import domain.statements.Statement;
import exceptions.InterpretorException;
import javafx.scene.control.Alert;
import repository.*;
import sun.util.resources.ms.CalendarData_ms_MY;
import utils.*;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private IRepository repo;
    private ExecutorService executor = Executors.newFixedThreadPool(2);;
    public Controller(Repository r){
        repo = r;
    }


    Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer,Integer> heap){
        return heap.entrySet().stream().filter(e->symTableValues.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }


    public List<PrgState> removeCompletedPrg(List<PrgState> inPrgList){
        return inPrgList.stream().filter(p->p.isNotCompleted()).collect(Collectors.toList());
    }

    public void oneStepForAllPrg(List<PrgState> prgList) {
        prgList.forEach(prg->repo.logProgStateExec(prg));

        List<Callable<PrgState>> callList = prgList.stream()
                .map((PrgState p)->(Callable<PrgState>)(()->{return p.oneStep();}))
                .collect(Collectors.toList());
        try {
            List<PrgState> newPrgList = executor.invokeAll(callList).stream()
                    .map(future -> {
                        try {
                            return future.get();
                        } catch (Exception e) {
                            Alert alert = new Alert(Alert.AlertType.WARNING);
                            alert.setTitle("Warning");
                            alert.setHeaderText("Exception");
                            alert.setContentText(e.getMessage());
                            alert.showAndWait();
                            System.exit(1);
                        }
                        return null;
                    })
                    .filter(p -> p != null)
                    .collect(Collectors.toList());


            prgList.addAll(newPrgList);
            prgList.forEach(prg->repo.logProgStateExec(prg));

            repo.setPrgList(prgList);
        }catch(InterruptedException ie){
            System.out.println(ie.getMessage());
        }

    }

    public void allStep(){
        executor = Executors.newFixedThreadPool(2);
        List<PrgState> prgList = removeCompletedPrg(repo.getPrgList());
        while(prgList.size()>0) {
            //garbage collector
            oneStepForAllPrg(prgList);
            prgList.forEach( p -> p.getHeap().setContent(conservativeGarbageCollector(p.getSymbols().getValues(),p.getHeap().getContent())));
            prgList = removeCompletedPrg(repo.getPrgList());
        }
        executor.shutdownNow();

        prgList.forEach(prg->repo.logProgStateExec(prg));


        //close open files
        try {
            List<PrgState> tmpList = repo.getPrgList();
            for (PrgState p : tmpList) {
                for (FileData fd : p.getFileTable().getValues()) {
                    fd.getFileDescriptor().close();
                }
            }
        }catch (IOException ie){
            System.out.println(ie.getMessage());
        }

        repo.setPrgList(prgList);
    }

    public Integer getNoProgramStates(){
        return repo.getPrgList().size();
    }

    public List<PrgState> getPrgStList(){
        return repo.getPrgList();
    }

    public Iterable<Integer> getOut(){
        return repo.getPrgList().get(0).getMessages().getAll();
    }

    public Iterable<Statement> getStackForPrg(int prgStateId){
        for (PrgState ps : repo.getPrgList()) {
            if (ps.getId() == prgStateId)
                return ps.getStack().getAll();
        }
        return null;
    }

    public IHeap<Integer,Integer> getHeap(){
        return repo.getPrgList().get(0).getHeap();
    }

    public HashMap<Integer,FileData> getFileTable(){
        return repo.getPrgList().get(0).getFileTable().getContent();
    }

    public HashMap<String,Integer> getSymTableForPrg(int id){
        for (PrgState ps : repo.getPrgList()) {
            if (ps.getId() == id)
                return ps.getSymbols().getContent();
        }
        return new HashMap<String,Integer>();
    }

    public ArrayList<Integer> getPrgStateIds() {
        ArrayList<Integer> list = (ArrayList<Integer>) repo.getPrgList()
                .stream()
                .map(PrgState::getId)
                .collect(Collectors.toList());
        return list;
    }

    public HashMap<Integer,Integer> getLatchTable(){
        return repo.getPrgList().get(0).getLatchTable().getContent();
    }

}
