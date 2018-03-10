package utils;
import java.util.Deque;
import java.util.ArrayDeque;

public class ExecStack<T> implements IExecStack<T> {
    private Deque<T> stack;
    public ExecStack(){
        stack = new ArrayDeque<>();
    }
    public void push(T e){
        stack.push(e);
    }

    public T pop(){
        return stack.pop();
    }

    public boolean isEmpty(){ return stack.size() == 0; }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        for(T e : stack)
            str.append(e + " \n");
        return str.toString();
    }

    @Override
    public Iterable<T> getAll() {
        return stack;
    }
}
