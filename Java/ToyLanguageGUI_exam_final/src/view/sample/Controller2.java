package view.sample;

import domain.FileData;
import domain.FileTable;
import domain.PrgState;
import domain.statements.Statement;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;

import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import repository.Repository;
import utils.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Controller2 {

    @FXML
    private TextField nrPrgStatesField;
    @FXML
    private TableView<KeyValuePair> HeapTable;
    @FXML
    private TableColumn<KeyValuePair,String> addressColumn;
    @FXML
    private TableColumn<KeyValuePair,String> valueColumn;
    @FXML
    private TableView<KeyValuePair> FileTable;
    @FXML
    private TableColumn<KeyValuePair,String> fileIdColumn;
    @FXML
    private TableColumn<KeyValuePair,String> fileColumn;
    @FXML
    private TableView<KeyValuePair> SymbolTable;
    @FXML
    private TableColumn<KeyValuePair,String> varNameColumn;
    @FXML
    private TableColumn<KeyValuePair,String> varValueColumn;
    @FXML
    private ListView<Integer> Out;
    @FXML
    private ListView<Integer> PrgStateIds;
    @FXML
    private ListView<Statement> ExeStack;
    @FXML
    private TableView<KeyValuePair> LatchTable;
    @FXML
    private TableColumn<KeyValuePair,String> id1Column;
    @FXML
    private TableColumn<KeyValuePair,String> id2Column;


    private controller.Controller ctrl;

    @FXML
    public void initialize(){
        Statement stmt = ListController.stmt;

        ExecStack<Statement> exec = new ExecStack<>();
        exec.push(stmt);
        Dictionary<String, Integer> symbolT = new Dictionary<>();
        OutList<Integer> messages = new OutList<>();
        domain.FileTable<Integer,FileData> fileTable = new FileTable<>();
        MyHeap<Integer,Integer> heap = new MyHeap<>();
        LatchTable<Integer,Integer> lt = new LatchTable<>();
        PrgState prg = new PrgState(exec,messages,symbolT, stmt,fileTable,heap,lt);
        Repository repo = new Repository("log.txt");

        repo.addPrgState(prg);
        ctrl = new controller.Controller(repo);

        updateNoPrgStates();
        updatePrgStateIds();
        PrgStateIds.getSelectionModel().select(0);
        updateOut();
        updateExeStack();
        updateHeap();
        updateFileTable();
        updateSymTable();


    }

    public void updateNoPrgStates(){
        nrPrgStatesField.setText(""+ctrl.getNoProgramStates());
        nrPrgStatesField.setEditable(false);
    }

    public void updatePrgStateIds(){

        PrgStateIds.setItems(FXCollections.observableArrayList(ctrl.getPrgStateIds()));
    }


    public void updateOut(){
        ObservableList<Integer> outList = FXCollections.observableArrayList();
        for (Integer i : ctrl.getOut())
            outList.add(i);
        Out.setItems(outList);
    }

    public void updateExeStack(){

        int id = 0;
        try{
            id = PrgStateIds.getSelectionModel().getSelectedItem();
        }
        catch(Exception ex)
        {}

        ObservableList<Statement> stack = FXCollections.observableArrayList();
        for (Statement st : ctrl.getStackForPrg(id))
            stack.add(st);
        ExeStack.setItems(stack);

    }

    public void updateHeap(){
        addressColumn.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("key"));
        valueColumn.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("value"));
        HashMap<Integer,Integer> h = ctrl.getHeap().getContent();
        HeapTable.getItems().clear();
        ObservableList<KeyValuePair> heapObs = FXCollections.observableArrayList();
        for(Map.Entry<Integer,Integer> e : h.entrySet()) {
            heapObs.add(new KeyValuePair(e.getKey().toString(), e.getValue().toString()));
        }
        HeapTable.setItems(heapObs);
    }

    public void updateFileTable(){
        fileIdColumn.setCellValueFactory(new PropertyValueFactory<>("key"));
        fileColumn.setCellValueFactory(new PropertyValueFactory<>("value"));
        HashMap<Integer,FileData> ft = ctrl.getFileTable();
        FileTable.getItems().clear();
        ObservableList<KeyValuePair> ftObs = FXCollections.observableArrayList();
        for(Map.Entry<Integer,FileData> e : ft.entrySet()) {
            ftObs.add(new KeyValuePair(e.getKey().toString(), e.getValue().toString()));
        }
        FileTable.setItems(ftObs);

    }

    public void updateSymTable(){
        int id = 0;
        try{
            id = PrgStateIds.getSelectionModel().getSelectedItem();
        }
        catch(Exception ex)
        {}
        varNameColumn.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("key"));
        varValueColumn.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("value"));
        HashMap<String,Integer> st = ctrl.getSymTableForPrg(id);
        SymbolTable.getItems().clear();
        ObservableList<KeyValuePair> stObs = FXCollections.observableArrayList();
        for(Map.Entry<String,Integer> e : st.entrySet()) {
            stObs.add(new KeyValuePair(e.getKey().toString(), e.getValue().toString()));
        }
        SymbolTable.setItems(stObs);
    }


    public void updateLatchTable(){
        id1Column.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("key"));
        id2Column.setCellValueFactory(new PropertyValueFactory<KeyValuePair,String>("value"));
        HashMap<Integer,Integer> lt = ctrl.getLatchTable();
        LatchTable.getItems().clear();
        ObservableList<KeyValuePair> stObs = FXCollections.observableArrayList();
        for(Map.Entry<Integer,Integer> e : lt.entrySet()) {
            stObs.add(new KeyValuePair(e.getKey().toString(), e.getValue().toString()));
        }
        LatchTable.setItems(stObs);
    }

    public void updateAll(){
        updateNoPrgStates();
        updatePrgStateIds();
        updateOut();
        updateExeStack();
        updateHeap();
        updateFileTable();
        updateSymTable();
        updateLatchTable();
    }


    @FXML
    public void prgIdSelected(){
        updateExeStack();
        updateSymTable();
    }

    @FXML
    public void runOneStepButtonPushed(){
        List<PrgState> prgList = ctrl.removeCompletedPrg(ctrl.getPrgStList());
        if(prgList.isEmpty())
        {
            Alert alert = new Alert(Alert.AlertType.WARNING);
            alert.setTitle("Warning!");
            alert.setHeaderText("Done");
            alert.setContentText("Stack is empty - The execution is done!");
            alert.showAndWait();
            return;
        }

        ctrl.oneStepForAllPrg(prgList);
        updateAll();
    }

}
