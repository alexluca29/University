using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Expressions;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Statements
{
    class AssignStmt : Statement
    {
        private String varName;
        private Expression expr;

        public AssignStmt(String v, Expression e)
        {
            this.varName = v;
            this.expr = e;
        }

        public PrgState execute(PrgState p)
        {
            ISymTable<String, int> symb = p.getSymbols();
            int result = expr.eval(symb);
            if (symb.contains(varName))
                symb.update(varName, result);
            else
                symb.add(varName, result);
           
            return p;
        }

      
        public  override String ToString()
        {
            return varName + '=' + expr;
        }
    }
}
