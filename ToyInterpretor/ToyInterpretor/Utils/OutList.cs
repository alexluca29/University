using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    class OutList<T> : IOutList<T>
    {
        private List<T> l;
        public OutList()
        {
            l = new List<T>();
        }


        public void addMsg(T m)
        {
            l.Add(m);
        }

        
        public override String ToString()
        {
            StringBuilder buff = new StringBuilder();
            foreach (T e in l)
                buff.Append("" + e + "\n");
            return buff.ToString();
        }

        
        public IEnumerable<T> getAll()
        {
            return l;
        }
    }
}
