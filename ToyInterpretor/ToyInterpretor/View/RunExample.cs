using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Controller;

namespace ToyInterpretor.View
{
    class RunExample : Command
    {
        private Ctrl ctr;
        public RunExample(String key, String desc, Ctrl ctr) : base(key,desc)
        {
            this.ctr = ctr;
        }
        
         public override void execute()
        {
            try
            {
                ctr.executeAll();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            } 
        }
    }
}
