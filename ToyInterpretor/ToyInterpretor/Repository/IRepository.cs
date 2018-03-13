using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Domain;

namespace ToyInterpretor.Repository
{
    interface IRepository
    {
        void addPrgState(PrgState p);
        PrgState getCurrentPrgState();
        void logProgStateExec();
    }
}
