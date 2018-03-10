package domain;

import java.util.Collection;
import java.util.HashMap;

public interface IFileTable<K,V> {
    V get(K key);
    boolean contains(K key);
    void remove(K key);
    void add(K key,V value);
    Iterable<K> getAll();
    Iterable<V> getValues();
    HashMap<K,V> getContent();
}
