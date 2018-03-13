using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyInterpretor.Utils;
using ToyInterpretor.Domain.Statements;

namespace ToyInterpretor.Domain
{
    class PrgState
    {
        private IExecStack<Statement> exec;
        private IOutList<int> messages;
        private ISymTable<String, int> symbolT;
        private Statement stmt;
        private IFileTable<int,FileData> fileTable;
        public PrgState(IExecStack<Statement> stack, IOutList<int> messages, ISymTable<String, int> symbolT, Statement stmt,IFileTable<int,FileData> ft)
        {
            this.exec = stack;
            this.messages = messages;
            this.symbolT = symbolT;
            this.stmt = stmt;
            this.fileTable = ft;
        }

        public IExecStack<Statement> getStack()
        {
            return exec;
        }

        public IOutList<int> getMessages()
        {
            return messages;
        }

        public ISymTable<String, int> getSymbols()
        {
            return symbolT;
        }

        public Statement getStatement()
        {
            return stmt;
        }

        public IFileTable<int, FileData> getFileTable() { return fileTable; }


        
        public override String ToString()
        {
            StringBuilder buff = new StringBuilder();
            buff.Append("\n");
            buff.Append("--------------------\n");
            buff.Append("Execution stack: \n");
            buff.Append("" + exec + "\n");
            buff.Append("Message list: \n");
            buff.Append(messages + "\n");
            buff.Append("Dictionary: \n");
            buff.Append("" + symbolT + "\n");
            buff.Append("Statement: \n");
            buff.Append("" + stmt + "\n");
            buff.Append("File table: \n");
            buff.Append("" + fileTable + "\n");
       
            return buff.ToString();
        }
    }
}
