using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;
using ToyInterpretor.Exceptions;

namespace ToyInterpretor.Domain.Expressions
{
    class ArithmeticExpression : Expression
    {
        private Char op;
        private Expression left, right;

        public ArithmeticExpression(char op, Expression left, Expression right)
        {
            this.op = op;
            this.left = left;
            this.right = right;
        }

        public int eval(ISymTable<String, int> symTable)
        {
            int left1 = left.eval(symTable);
            int right1 = right.eval(symTable);
            if (op == '+')
            return left1 + right1;
            if (op == '-')
            return left1 - right1;
            if (op == '*')
            return left1 * right1;
            if (op == '/')
            if (right1 == 0)
                throw new DivisionException("Division by zero");
            return left1 / right1;
        }

        public override String ToString()
        {
            return left.ToString() +op+right.ToString();
        }
    }
}
