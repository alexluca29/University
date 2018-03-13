using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Domain
{
    class FileTable<K,V> : IFileTable<K,V>
    {
        private Dictionary<K, V> fileTable = new Dictionary<K, V>();
        public FileTable() { }
        public V get(K key)
        {
            return fileTable[key];
        }

        public Boolean contains(K key)
        {
            return fileTable.ContainsKey(key);
        }

        public void remove(K key)
        {
            fileTable.Remove(key);
        }

        public void add(K key, V value)
        {
            fileTable.Add(key, value);
        }

        public IEnumerable<K> getAll()
        {
            return fileTable.Keys;
        }

        public IEnumerable<V> getValues()
        {
            return fileTable.Values;
        }

        
        public override String ToString()
        {
            return fileTable.ToString();
        }
    }
}
