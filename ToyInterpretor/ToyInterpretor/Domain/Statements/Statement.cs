using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Domain.Statements
{
    interface Statement
    {
        PrgState execute(PrgState p);
    }
}
