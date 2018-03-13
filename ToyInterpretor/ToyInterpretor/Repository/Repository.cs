using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain;
using ToyInterpretor.Exceptions;
using System.IO;
using ToyInterpretor.Domain.Statements;

namespace ToyInterpretor.Repository
{
    class Repo : IRepository
    {
        private List<PrgState> a;
        private String logFile;

        public Repo(String fileName)
        {
            logFile = fileName;
            a = new List<PrgState>();
        }

        public void addPrgState(PrgState p)
        {
            a.Add(p);
        }

        public PrgState getCurrentPrgState()
        {
            if (a.Count <= 0)
                throw new RepoException();
            return a[0];
        }

        public void logProgStateExec()
        {
            try 
             {
                TextWriter tw = new StreamWriter(new FileStream(logFile, FileMode.Append));
                tw.WriteLine("------------------");
                tw.WriteLine("ExeStack: ");
                PrgState current = getCurrentPrgState();
                foreach (Statement s in current.getStack().getAll()) {
                    tw.WriteLine(s);
                }
                tw.WriteLine("\n");
                tw.WriteLine("SymTable: ");
                foreach (String s in current.getSymbols().getAll())
                {
                    int val = current.getSymbols().get(s);
                    tw.WriteLine(s + "->" + val);
                }
                tw.WriteLine("\n");
                tw.WriteLine("Out: ");
                foreach (int i in current.getMessages().getAll())
                {
                    tw.WriteLine(i);
                }
                tw.WriteLine("\n");
                tw.WriteLine("FileTable: ");
                foreach (int i in current.getFileTable().getAll())
                {
                    FileData val = current.getFileTable().get(i);
                    tw.WriteLine(i + "->" + val);
                }
                tw.WriteLine("\n");
               
                tw.Close();
            }
            catch (IOException ioe)
            {
                throw new Exception(ioe.Message);
            }
        }
    }
}
