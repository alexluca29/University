using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.View
{
    class ExitCommand : Command
    {
        public ExitCommand(String key, String desc) : base(key,desc)
        {
        }
        
        public override void execute()
        {
            Environment.Exit(0);
        }
    }
}
