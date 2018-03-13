using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;


namespace ToyInterpretor.Domain.Expressions
{
    class ConstExpression : Expression
    {
        private int constant;

        public ConstExpression(int val)
        {
            constant = val;
        }

        public int eval(ISymTable<String, int> symb)
        {
            return constant;
        }

        public override string ToString()
        {
            return ""+constant;
        }
    }
}
