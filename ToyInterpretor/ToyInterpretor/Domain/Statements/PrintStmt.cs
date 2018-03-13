using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Expressions;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Statements
{
    class PrintStmt : Statement
    {
        private Expression expr;
        public PrintStmt(Expression e)
        {
            expr = e;
        }

        
        public PrgState execute(PrgState p)
        {
         
           IOutList<int> list = p.getMessages();
           ISymTable<String, int> st = p.getSymbols();
           int res = expr.eval(st);
           list.addMsg(res);
      
            return p;
        }

        
        public override String ToString()
        {
            return "print(" + expr + ")";
        }
    }
}
