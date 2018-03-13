using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ToyInterpretor.Domain
{
    class FileData
    {
        private String filename;
        private BufferedStream fileDescriptor;

        public String getFilename() { return filename; }
        public BufferedStream getFileDescriptor() { return fileDescriptor; }

        public FileData(String fn, BufferedStream fd)
        {
            filename = fn;
            fileDescriptor = fd;
        }

        
        public override String ToString()
        {
            return filename;
        }
    }
}
