using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Statements;
using ToyInterpretor.Controller;
using ToyInterpretor.Domain.Expressions;
using ToyInterpretor.Utils;
using ToyInterpretor.Repository;
using ToyInterpretor.Domain;


namespace ToyInterpretor.View
{
    class Interpretor
    {
        public static void Main(String[] args)
        {
            Statement ex1 = new CompStmt(new OpenRFile("var_f", "test.in"),
                    new CompStmt(new ReadFile(new VarExpression("var_f"), "var_c"),
                            new CompStmt(new PrintStmt(new VarExpression("var_c")),
                                    new CompStmt(new IfStmt(new VarExpression("var_c"),
                                            new CompStmt(new ReadFile(new VarExpression("var_f"), "var_c"), new PrintStmt(new VarExpression("var_c"))),
                                            new PrintStmt(new ConstExpression(0))),
                                            new CloseRFile(new VarExpression("var_f"))))));
            ExecStack<Statement> exec = new ExecStack<Statement>();
            exec.push(ex1);
            SymTable<String, int> symbolT = new SymTable<String, int>();
            OutList<int> messages = new OutList<int>();
            FileTable<int, FileData> fileTable = new FileTable<int,FileData>();
            PrgState prg = new PrgState(exec, messages, symbolT, ex1, fileTable);
            Repo repo = new Repo("log.txt");
            Ctrl ctrl1 = new Ctrl(repo);
            repo.addPrgState(prg);

            //ctrl1.executeAll();
                     
        
            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit"));
            menu.addCommand(new RunExample("1", ex1.ToString(), ctrl1));
         
            menu.show();

        }
    
    }
}
