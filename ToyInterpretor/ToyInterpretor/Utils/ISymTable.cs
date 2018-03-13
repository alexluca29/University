using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyInterpretor.Utils
{
    public interface ISymTable<K,V>
    {
        V get(K key);
        Boolean contains(K key);
        void add(K k, V v);
        void update(K k, V v);
        IEnumerable<K> getAll();
        IEnumerable<V> getValues(); //collection?
    }
}
