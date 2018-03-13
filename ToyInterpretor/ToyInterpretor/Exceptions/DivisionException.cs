using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Exceptions
{
    class DivisionException : System.Exception
    {
        public DivisionException() { }
        public DivisionException(String msg) : base(msg){ }
    }
}
