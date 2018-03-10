package exceptions;

public class DivisionException extends RuntimeException {
    public DivisionException(){}
    public DivisionException(String msg){
        super(msg);
    }
}
