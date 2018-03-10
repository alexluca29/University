package utils;

import javafx.beans.property.SimpleStringProperty;

public class KeyValuePair {

    private final SimpleStringProperty value=new SimpleStringProperty("");
    private final SimpleStringProperty key=new SimpleStringProperty("");

    public KeyValuePair(String k,String v){
        setValue(v);
        setKey(k);
    }

    public String getKey() {
        return key.get();
    }

    public SimpleStringProperty keyProperty() {
        return key;
    }

    public void setKey(String key) {
        this.key.set(key);
    }


    public String getValue() {
        return value.get();
    }

    public SimpleStringProperty valueProperty() {
        return value;
    }

    public void setValue(String value) {
        this.value.set(value);
    }




}
