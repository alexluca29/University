package utils;

import java.util.Collection;
import java.util.HashMap;

public interface IDictionary<K,V> {
    V get(K e);
    boolean contains(K e);
    void add(K k,V v);
    void update(K k,V v);
    Iterable<K> getAll();
    Collection<V> getValues();
    IDictionary<K,V> copy();
    HashMap<K,V> getContent();
}
