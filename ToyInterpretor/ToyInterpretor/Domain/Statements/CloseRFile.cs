using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Expressions;
using System.IO;

namespace ToyInterpretor.Domain.Statements
{
    class CloseRFile : Statement
    {
        private Expression expFile;
        public CloseRFile(Expression ef)
        {
            expFile = ef;
        }


        public Boolean exists(PrgState p, int i)
        {
            IFileTable<int, FileData> ft = p.getFileTable();
            foreach (FileData key in ft.getValues())
            {
                if (key.getFileDescriptor() != null)
                    return true;
            }
            return false;
        }

        
        public PrgState execute(PrgState p)
        {
            try
            {
                int value = expFile.eval(p.getSymbols());
                if (!exists(p, value))
                    throw new Exception("File not found");
                BufferedStream buff = p.getFileTable().get(value).getFileDescriptor();

                buff.Close();

                p.getFileTable().remove(value);
            }
            catch (IOException ioe)
            {
                throw new IOException(ioe.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }


            return p;
        }

        
        public override String ToString()
        {
            return "closeFile(" + expFile + ")";
        }
    }
}
