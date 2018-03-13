using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Exceptions
{
    class ADTException : Exception
    {
        ADTException() { }
        ADTException(String msg) : base(msg) { }
    }
}
