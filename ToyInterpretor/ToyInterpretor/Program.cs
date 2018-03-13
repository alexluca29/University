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

namespace ToyInterpretor
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Statement ex1 = new CompStmt(new AssignStmt("v", new ConstExpression(2)), new PrintStmt(new VarExpression("v")));
            ExecStack<Statement> exec = new ExecStack<Statement>();
            exec.push(ex1);
            SymTable<String, int> symbolT = new SymTable<string, int>();
            OutList<int> messages = new OutList<int>();
          //  FileTable<Integer, FileData> fileTable = new FileTable<>();
         //   MyHeap<Integer, Integer> heap = new MyHeap<>();
            PrgState prg = new PrgState(exec, messages, symbolT, ex1);
            Repo repo = new Repo();
            Ctrl ctrl1 = new Ctrl(repo);
            repo.addPrgState(prg);

            //ctrl1.executeAll();
            //Console.ReadLine();

            Statement ex2 = new CompStmt(new AssignStmt("a", new ArithmeticExpression('+', new ConstExpression(2), new
                    ArithmeticExpression('*', new ConstExpression(3), new ConstExpression(5)))),
                    new CompStmt(new AssignStmt("b", new ArithmeticExpression('+', new VarExpression("a"), new
                    ConstExpression(1))), new PrintStmt(new VarExpression("b"))));

            ExecStack<Statement> exec2 = new ExecStack<Statement>();
            exec2.push(ex2);
            SymTable<String, int> symbolT2 = new SymTable<string, int>();
            OutList<int> messages2 = new OutList<int>();
            //  FileTable<Integer, FileData> fileTable = new FileTable<>();
            //   MyHeap<Integer, Integer> heap = new MyHeap<>();
            PrgState prg2 = new PrgState(exec2, messages2, symbolT2, ex2);
            Repo repo2 = new Repo();
            Ctrl ctrl2 = new Ctrl(repo2);
            repo2.addPrgState(prg2);

            //ctrl2.executeAll();
            //Console.ReadLine();

            Statement ex3 = new CompStmt(new AssignStmt("a", new ArithmeticExpression('-', new ConstExpression(2), new ConstExpression(2))),
                        new CompStmt(new IfStmt(new VarExpression("a"), new AssignStmt("v", new ConstExpression(2)), new
                        AssignStmt("v", new ConstExpression(3))), new PrintStmt(new VarExpression("v"))));
            ExecStack<Statement> exec3 = new ExecStack<Statement>();
            exec3.push(ex3);
            SymTable<String, int> symbolT3 = new SymTable<string, int>();
            OutList<int> messages3 = new OutList<int>();
            //  FileTable<Integer, FileData> fileTable = new FileTable<>();
            //   MyHeap<Integer, Integer> heap = new MyHeap<>();
            PrgState prg3 = new PrgState(exec3, messages3, symbolT3, ex3);
            Repo repo3 = new Repo();
            Ctrl ctrl3 = new Ctrl(repo3);
            repo2.addPrgState(prg3);

            ctrl3.executeAll();
            Console.ReadLine();
            */


        }
    }
}
