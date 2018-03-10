package utils;

public interface IOutList<T> {
    void addMsg(T e);
    Iterable<T> getAll();
}
