using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;

namespace ToyInterpretor.Domain.Statements
{
    class CompStmt : Statement
    {
        private Statement s1;
        private Statement s2;
        public CompStmt(Statement s1, Statement s2)
        {
            this.s1 = s1;
            this.s2 = s2;
        }

        
        public PrgState execute(PrgState p)
        {
            IExecStack<Statement> stack = p.getStack();
            stack.push(s2);
            stack.push(s1);
            return p;
        }

        
        public override String ToString()
        {
            return s1.ToString() + "\n" + s2.ToString();
        }
    }
}
