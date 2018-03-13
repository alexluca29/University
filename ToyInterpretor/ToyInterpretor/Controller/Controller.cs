using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Repository;
using ToyInterpretor.Utils;
using ToyInterpretor.Domain;
using ToyInterpretor.Domain.Statements;

namespace ToyInterpretor.Controller
{
    class Ctrl
    {
        private IRepository repo;
        public Ctrl(IRepository r)
        {
            repo = r;
        }

        public void executeOneStep()
        {
            PrgState current = repo.getCurrentPrgState();
            if (!current.getStack().isEmpty())
            {
                Statement s = current.getStack().pop();
                s.execute(current);
            }
            //Console.WriteLine(current);
        }

      
        public void executeAll()
        {
            PrgState currentr = repo.getCurrentPrgState();

            try
            { 
           
                PrgState current = repo.getCurrentPrgState();
                while (!current.getStack().isEmpty())
                {
                    executeOneStep();
                    repo.logProgStateExec();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            
            finally
            {
                try
                {
                    foreach (FileData fd in currentr.getFileTable().getValues())
                    {
                        fd.getFileDescriptor().Close();
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error at closing file" + e);
                }
            }
            
        }
    }
}
