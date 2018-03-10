package utils;

import java.util.HashMap;
import java.util.Map;

public interface ILatchTable<K,V> {
    void add(K key,V value);
    void update(K key,V value);
    boolean contains(K key);
    V get(K key);
    Iterable<K> getAll();
    void setContent(Map<K,V> map);
    HashMap<K,V> getContent();
}
