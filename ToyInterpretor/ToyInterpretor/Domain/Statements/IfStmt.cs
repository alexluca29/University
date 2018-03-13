using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain.Expressions;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Statements
{
    class IfStmt : Statement
    {
        private Expression condition;
        private Statement TrueS, FalseS;
        public IfStmt(Expression e, Statement s1, Statement s2)
        {
            this.condition = e;
            this.TrueS = s1;
            this.FalseS = s2;
        }

        
        public PrgState execute(PrgState p)
        {
       
            IExecStack<Statement> s = p.getStack();
            ISymTable<String, int> st = p.getSymbols();
            if (this.condition.eval(st) == 0)
                 s.push(this.TrueS);
            else
                 s.push(this.FalseS);   
            return p;
        }

         public override String ToString()
        {
            return "if(" + condition + ") then " + TrueS + " else " + FalseS;
        }

    }
}
