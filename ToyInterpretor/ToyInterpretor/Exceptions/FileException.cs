using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Exceptions
{
    class FileException : Exception
    {
        FileException() { }
        FileException(String msg) : base(msg){ }
    }
}
