using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Expressions
{
    class VarExpression : Expression
    {
        private String varName;
        public VarExpression(String varName)
        {
            this.varName = varName;
        }

        public int eval(ISymTable<String, int> symbTable) // throws RuntimeException
        {
           if (symbTable.contains(varName))
              return symbTable.get(varName);
           throw new SystemException("Not found");
        }

            
        public override String ToString()
        {
            return varName;
        }
    }
}
