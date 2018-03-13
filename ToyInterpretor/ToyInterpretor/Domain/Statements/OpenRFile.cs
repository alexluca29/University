using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ToyInterpretor.Domain.Statements
{
    class OpenRFile : Statement
    {
        private String varFile;
        private String nameFile;
        public OpenRFile(String vf, String nf)
        {
            varFile = vf;
            nameFile = nf;
        }

        private Boolean exists(PrgState p, String fn)
        {
            IFileTable<int, FileData> ft = p.getFileTable();
            foreach (FileData key in ft.getValues())
            {
                if (key.getFilename().Equals(fn))
                    return true;
            }
            return false;
        }

        
        public PrgState execute(PrgState p)
        {
            if (exists(p, nameFile))
                throw new Exception("File already open");
            try
            {
                BufferedStream buff = new BufferedStream(new FileStream(nameFile,FileMode.Open));
                FileData fd = new FileData(nameFile, buff);
                int id = IDGenerator.generateID();
                p.getFileTable().add(id, fd);
                if (p.getSymbols().contains(varFile))
                    p.getSymbols().update(varFile, id);
                else
                    p.getSymbols().add(varFile, id);
            }
            catch (IOException ioe)
            {
                throw new IOException(ioe.Message);
            }
            return p;
        }

        
        public override String ToString()
        {
            return "openFile(" + varFile + "," + nameFile + ")";
        }
    }
}
