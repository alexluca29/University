using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    interface IOutList<T>
    {
        void addMsg(T e);
        IEnumerable<T> getAll();
    }
}
