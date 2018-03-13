using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Exceptions
{
    class RepoException : Exception
    {
        public RepoException() { }
        public RepoException(String msg) : base(msg) { }
    }
}
