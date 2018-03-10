package utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Dictionary<K,V> implements IDictionary<K,V> {
    private HashMap<K,V> container;
    public Dictionary(){
        container = new HashMap<K,V>();
    }
    public V get(K k){
        return container.get(k);
    }
    public boolean contains(K k){
        return container.containsKey(k);
    }
    public void add(K k,V v){
        container.put(k,v);
    }
    public void update(K k,V v){
        container.put(k,v);
    }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        for (K k : container.keySet())
            str.append("" + k + ' ' + container.get(k)+"\n");
        return str.toString();
    }

    @Override
    public Iterable<K> getAll(){
        return container.keySet();
    }

    public Collection<V> getValues(){
        return container.values();
    }



    @Override
    public IDictionary<K,V> copy(){
        IDictionary<K,V> newDict = new Dictionary<>();
        for (Map.Entry<K,V> el : container.entrySet())
            newDict.add(el.getKey(),el.getValue());
        return newDict;
    }

    public HashMap<K,V> getContent(){
        return container;
    }
}
