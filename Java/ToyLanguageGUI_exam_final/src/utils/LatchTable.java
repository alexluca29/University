package utils;

import java.util.HashMap;
import java.util.Map;

public class LatchTable<K,V> implements ILatchTable<K,V> {
    private HashMap<K,V> map;

    public LatchTable(){
        map = new HashMap<>();
    }

    public void add(K key,V value){
        map.put(key,value);
    }

    public void update(K key,V value){
        map.put(key,value);
    }

    public boolean contains(K key){
        return map.containsKey(key);
    }

    public V get(K key){
        return map.get(key);
    }

    public Iterable<K> getAll() {
        return map.keySet();
    }

    public void setContent(Map<K,V> newMap)
    {
        map = new HashMap<K,V>(newMap);
    }

    public HashMap<K,V> getContent(){
        return map;
    }

    @Override
    public String toString(){
        return map.toString();
    }
}
