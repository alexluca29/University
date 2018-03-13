using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    class SymTable<K,V> : ISymTable<K,V>
    {
        private Dictionary<K, V> symTable;

        public SymTable()
        {
            symTable = new Dictionary<K, V>();
        }

        public V get(K key)
        {
            return symTable[key];
        }

        public Boolean contains(K key)
        {
            return symTable.ContainsKey(key);
        }

        public void add(K k,V v)
        {
            symTable[k] = v;
        }

        public void update(K k,V v)
        {
            symTable[k] = v;
        }

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            foreach (K k in symTable.Keys.ToArray())
            {
                buff.AppendLine("" + k + ' ' + symTable[k]);
            }
            return buff.ToString();
        }

        public IEnumerable<K> getAll()
        {
            return symTable.Keys.AsEnumerable();
        } 

        public IEnumerable<V> getValues()
        {
            return symTable.Values.AsEnumerable();
        }

    }
}
