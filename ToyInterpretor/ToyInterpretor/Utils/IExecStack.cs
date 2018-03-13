using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    public interface IExecStack<T>
    {
        void push(T k);
        T pop();
        Boolean isEmpty();
        IEnumerable<T> getAll();
    }
}
