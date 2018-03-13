using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    class ExecStack<T> : IExecStack<T>
    {
        private Stack<T> stack;
        public ExecStack()
        {
            stack = new Stack<T>();
        }
        public void push(T e)
        {
            stack.Push(e);
        }

        public T pop()
        {
            return stack.Pop();
        }

        public Boolean isEmpty() { return stack.Count() == 0; }

        
        public override String ToString()
        {
            StringBuilder str = new StringBuilder();
            foreach (T e in stack)
                str.Append(e + " \n");
            return str.ToString();
        }

        
        public IEnumerable<T> getAll()
        {
            return stack;
        }
    }
}
