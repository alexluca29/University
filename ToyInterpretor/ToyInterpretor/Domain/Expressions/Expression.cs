using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Expressions
{
    public interface Expression
    {
       int eval(ISymTable<String, int> symb);
    }
}
