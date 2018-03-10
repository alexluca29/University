package domain;

public class IDGenerator {
    static private int id=0;
    static public int generateID(){
        id = id + 1;
        return id;
    }
}
