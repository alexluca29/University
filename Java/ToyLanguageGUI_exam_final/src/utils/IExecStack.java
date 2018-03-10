package utils;
import java.util.Deque;

public interface IExecStack<T> {
    void push(T k);
    T pop();
    boolean isEmpty();
    Iterable<T> getAll();
}
