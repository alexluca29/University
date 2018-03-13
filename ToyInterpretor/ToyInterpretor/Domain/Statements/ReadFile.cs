using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Expressions;
using System.IO;

namespace ToyInterpretor.Domain.Statements
{
    class ReadFile : Statement
    {
        private Expression expFileId;
        private String varName;

        public ReadFile(Expression ef, String vn)
        {
            expFileId = ef;
            varName = vn;
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
            int value = expFileId.eval(p.getSymbols());
            if (!exists(p, value))
                throw new Exception("File not found");
            try
            {
                BufferedStream buff = p.getFileTable().get(value).getFileDescriptor();
                StreamReader sr = new StreamReader(buff);
                String line = sr.ReadLine();
                //System.out.println(line);
                int i;
                if (line.Equals(null))
                    i = 0;
                else
                    i = int.Parse(line);
                if (p.getSymbols().contains(varName))
                    p.getSymbols().update(varName, i);
                else
                    p.getSymbols().add(varName, i);
            }
            catch (IOException ioe)
            {
                throw new IOException(ioe.Message);
            }
            return p;
        }

        
        public override String ToString()
        {
            return "readFile(" + expFileId + "," + varName + ")";
        }
    }
}
