using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Domain
{
    class IDGenerator
    {
        static private int id = 0;
        static public int generateID()
        {
            return id++;
        }
    }
}
