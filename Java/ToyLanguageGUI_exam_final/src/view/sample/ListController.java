package view.sample;

import domain.expressions.*;
import domain.statements.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.stage.Stage;

public class ListController {

    @FXML
    private ListView<Statement> listView;


    public static Statement stmt;


    @FXML
    public void initialize(){

        listView.setItems(getProgramList());
        listView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        listView.getSelectionModel().clearAndSelect(0);

    }


    private ObservableList<Statement> getProgramList(){
        Statement ex1 = new CompStmt(new OpenRFile("var_f","test.in"),
                new CompStmt(new ReadFile(new VarExpression("var_f"),"var_c"),
                        new CompStmt(new PrintStmt(new VarExpression("var_c")),
                                new CompStmt(new IfStmt(new VarExpression("var_c"),
                                        new CompStmt(new ReadFile(new VarExpression("var_f"),"var_c"),new PrintStmt(new VarExpression("var_c"))),
                                        new PrintStmt(new ConstExpression(0)) ),
                                        new CloseRFile(new VarExpression("var_f")) ))));


        Statement ex2=new CompStmt(new AssignStmt("v",new ConstExpression(10)),
                new CompStmt(new newH("v",new ConstExpression(20)),
                        new CompStmt(new newH("a",new ConstExpression(22)),
                                new CompStmt(new wH("a",new ConstExpression(30)),
                                        new CompStmt(new PrintStmt(new VarExpression("a")),
                                                new CompStmt(new PrintStmt(new rH("a")),
                                                        new AssignStmt("a",new ConstExpression(0))))))));
        Statement ex3 = new CompStmt(new AssignStmt("v",new ConstExpression(6)),
                new CompStmt(new WhileStmt(new ArithmeticExpression('-',new VarExpression("v"),new ConstExpression(4)),
                        new CompStmt(new PrintStmt(new VarExpression("v")),new AssignStmt("v",new ArithmeticExpression('-',
                                new VarExpression("v"),new ConstExpression(1))))),
                        new PrintStmt(new VarExpression("v"))));


        Statement ex4 = new CompStmt(new AssignStmt("v",new ConstExpression(10)),new CompStmt(new newH("a",new ConstExpression(22)),
                new CompStmt(new ForkStmt(new CompStmt(new wH("a",new ConstExpression(30)),
                        new CompStmt(new AssignStmt("v",new ConstExpression(32)),new CompStmt(new PrintStmt(new VarExpression("v")),
                                new PrintStmt(new rH("a")))))),new CompStmt(new PrintStmt(new VarExpression("v")),new PrintStmt(new rH("a"))))));


        Statement ex5 = new CompStmt(new AssignStmt("v",new ConstExpression(20)),new ForStmt(new AssignStmt("v",new ConstExpression(0)),
                                    new LessThan(new VarExpression("v"),new ConstExpression(3)),new AssignStmt("v",new ArithmeticExpression('+',
                                            new VarExpression("v"),new ConstExpression(1))),new PrintStmt(new VarExpression("v"))));


        Statement ex6 = new CompStmt(new AssignStmt("v",new ConstExpression(0)),new CompStmt(new RepeatUntil(
                                    new CompStmt(new ForkStmt(new CompStmt(new PrintStmt(new VarExpression("v")),new AssignStmt("v",new ArithmeticExpression(
                                            '-',new VarExpression("v"),new ConstExpression(1))))),
                                            new AssignStmt("v",new ArithmeticExpression('+',new VarExpression("v"),new ConstExpression(1)))),
                                            new Equal(new VarExpression("v"),new ConstExpression(3))),
                                            new CompStmt(new AssignStmt("x",new ConstExpression(1)),
                                            new CompStmt(new AssignStmt("y",new ConstExpression(2)),
                                            new CompStmt(new AssignStmt("z",new ConstExpression(3)),
                                            new CompStmt(new AssignStmt("w",new ConstExpression(4)),
                                            new PrintStmt(new ArithmeticExpression('*',new VarExpression("v"),new ConstExpression(10)))))))
                                    ));

        Statement ex7 = new CompStmt(new newH("v1",new ConstExpression(2)),
                                    new CompStmt(new newH("v2",new ConstExpression(3)),
                                            new CompStmt(new newH("v3",new ConstExpression(4)),
                                                    new CompStmt(new NewLatch("cnt",new rH("v2")),
                                                            new CompStmt(new ForkStmt  (new CompStmt( (new wH("v1",new ArithmeticExpression('*',new rH("v1"),new ConstExpression(10)))),
                                                                    new CompStmt(new PrintStmt(new rH("v1")),
                                                                            new CompStmt(new CountDown("cnt"),
                                                                                    new ForkStmt (new CompStmt(new wH("v2",new ArithmeticExpression('*',new rH("v2"),new ConstExpression(10))),
                                                                                            new CompStmt(new PrintStmt(new rH("v2")),
                                                                                                    new CompStmt(new CountDown("cnt"),
                                                                                                            new ForkStmt (new CompStmt(new wH("v3",new ArithmeticExpression('*',new rH("v3"),new ConstExpression(10))),
                                                                                                                    new CompStmt(new PrintStmt(new rH("v3")),
                                                                                                                            new CountDown("cnt")))))))))))),
                                                                    new CompStmt(new Await("cnt"),
                                                                            new CompStmt(new PrintStmt(new ConstExpression(100)),
                                                                                    new CompStmt(new CountDown("cnt"),new PrintStmt(new ConstExpression(100))))))))));

        ObservableList<Statement> statements = FXCollections.observableArrayList(ex1,ex2,ex3,ex4,ex5,ex6,ex7);
        return statements;
    }


    public void listViewButtonPressed(){
            int index = listView.getSelectionModel().getSelectedIndex();
            ObservableList<Statement> list = listView.getItems();
            stmt = list.get(index);

            Stage stage = new Stage();
            try {
                Parent root = FXMLLoader.load(getClass().getResource("SecondWindow.fxml"));
                stage.setTitle("Execution");
                stage.setScene(new Scene(root, 300, 275));
                stage.show();
            }
            catch(Exception e){
                e.printStackTrace();
            }
    }




}
