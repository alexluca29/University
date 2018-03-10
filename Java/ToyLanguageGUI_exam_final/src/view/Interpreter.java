package view;

import domain.*;
import controller.*;
import domain.expressions.*;
import domain.statements.*;
import repository.*;
import utils.*;

public class Interpreter {
    public static void main(String[] args) {
/*
        Statement ex1 = new CompStmt(new OpenRFile("var_f","test.in"),
                new CompStmt(new ReadFile(new VarExpression("var_f"),"var_c"),
                        new CompStmt(new PrintStmt(new VarExpression("var_c")),
                                new CompStmt(new IfStmt(new VarExpression("var_c"),
                                        new CompStmt(new ReadFile(new VarExpression("var_f"),"var_c"),new PrintStmt(new VarExpression("var_c"))),
                                        new PrintStmt(new ConstExpression(0)) ),
                                        new CloseRFile(new VarExpression("var_f")) ))));
        ExecStack<Statement> exec = new ExecStack<>();
        exec.push(ex1);
        Dictionary<String, Integer> symbolT = new Dictionary<>();
        OutList<Integer> messages = new OutList<>();
        FileTable<Integer,FileData>  fileTable = new FileTable<>();
        MyHeap<Integer,Integer> heap = new MyHeap<>();
        PrgState prg = new PrgState(exec, messages, symbolT, ex1,fileTable,heap);
        Repository repo = new Repository("log.txt");
        Controller ctrl1 = new Controller(repo);
        repo.addPrgState(prg);

        //ctrl1.executeAll();


        Statement ex2=new CompStmt(new AssignStmt("v",new ConstExpression(10)),
                            new CompStmt(new newH("v",new ConstExpression(20)),
                            new CompStmt(new newH("a",new ConstExpression(22)),
                            new CompStmt(new wH("a",new ConstExpression(30)),
                            new CompStmt(new PrintStmt(new VarExpression("a")),
                            new CompStmt(new PrintStmt(new rH("a")),
                                    new AssignStmt("a",new ConstExpression(0))))))));
        ExecStack<Statement> exec2 = new ExecStack<>();
        exec2.push(ex2);
        Dictionary<String, Integer> symbolT2 = new Dictionary<>();
        OutList<Integer> messages2 = new OutList<>();
        FileTable<Integer,FileData>  fileTable2 = new FileTable<>();
        MyHeap<Integer,Integer> heap2 = new MyHeap<>();
        PrgState prg2 = new PrgState(exec2,messages2,symbolT2, ex2,fileTable2,heap2);
        Repository repo2 = new Repository("log2.txt");
        Controller ctr2 = new Controller(repo2);
        repo2.addPrgState(prg2);
*/

//        ctr2.executeAll();

/*
        Expression a3 = new ArithmeticExpression('+', new ConstExpression(10),
                new LessThan(new ConstExpression(2), new ConstExpression(6)));
  */
/*
        Statement ex3 = new CompStmt(new AssignStmt("v",new ConstExpression(6)),
                                    new CompStmt(new WhileStmt(new ArithmeticExpression('-',new VarExpression("v"),new ConstExpression(4)),
                                            new CompStmt(new PrintStmt(new VarExpression("v")),new AssignStmt("v",new ArithmeticExpression('-',
                                                    new VarExpression("v"),new ConstExpression(1))))),
                                                        new PrintStmt(new VarExpression("v"))));

                                                        */
/*
        Statement ex4 = new CompStmt(new AssignStmt("v",new ConstExpression(6)),
                new AssignStmt("v",new ArithmeticExpression('-',new VarExpression("v"),new ConstExpression(4))));
*/
/*
        ExecStack<Statement> exec3 = new ExecStack<>();
        exec3.push(ex3);
        Dictionary<String, Integer> symbolT3 = new Dictionary<>();
        OutList<Integer> messages3 = new OutList<>();
        FileTable<Integer,FileData>  fileTable3 = new FileTable<>();
        MyHeap<Integer,Integer> heap3 = new MyHeap<>();
        PrgState prg3 = new PrgState(exec3,messages3,symbolT3, ex3,fileTable3,heap3);
        Repository repo3 = new Repository("log3.txt");
        Controller ctr3 = new Controller(repo3);
        repo3.addPrgState(prg3);


        Statement ex4 = new CompStmt(new AssignStmt("v",new ConstExpression(10)),new CompStmt(new newH("a",new ConstExpression(22)),
                            new CompStmt(new ForkStmt(new CompStmt(new wH("a",new ConstExpression(30)),
                                    new CompStmt(new AssignStmt("v",new ConstExpression(32)),new CompStmt(new PrintStmt(new VarExpression("v")),
                                            new PrintStmt(new rH("a")))))),new CompStmt(new PrintStmt(new VarExpression("v")),new PrintStmt(new rH("a"))))));
        ExecStack<Statement> exec4 = new ExecStack<>();
        exec4.push(ex4);
        Dictionary<String, Integer> symbolT4 = new Dictionary<>();
        OutList<Integer> messages4 = new OutList<>();
        FileTable<Integer,FileData>  fileTable4 = new FileTable<>();
        MyHeap<Integer,Integer> heap4 = new MyHeap<>();
        PrgState prg4 = new PrgState(exec4,messages4,symbolT4, ex4,fileTable4,heap4);
        Repository repo4 = new Repository("log4.txt");
        Controller ctr4 = new Controller(repo4);
        repo4.addPrgState(prg4);


        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), ctrl1));
        menu.addCommand(new RunExample("2", ex2.toString(), ctr2));
        menu.addCommand(new RunExample("3", ex3.toString(), ctr3));
        menu.addCommand(new RunExample("4", ex4.toString(), ctr4));
        menu.show();
*/
    }
}
