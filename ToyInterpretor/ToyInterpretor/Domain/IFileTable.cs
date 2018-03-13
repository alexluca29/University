using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Domain
{
    interface IFileTable<K,V>
    {
        V get(K key);
        Boolean contains(K key);
        void remove(K key);
        void add(K key, V value);
        IEnumerable<K> getAll();
        IEnumerable<V> getValues();
    }
}
