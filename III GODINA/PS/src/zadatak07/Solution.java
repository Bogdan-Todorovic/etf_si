package zadatak07;

import java.util.HashMap;

interface Subject{
    void f1();
    void f2();
    int f3();
    int id();
}

class RealSubject implements Subject{
    @Override
    public void f1() {

    }

    @Override
    public void f2() {

    }

    @Override
    public int f3() {
        return 0;
    }

    @Override
    public int id() {
        return 0;
    }
}
interface HttpInterface{
    int get(String address, HashMap<String, String> parameters);
    String post(String address, HashMap<String, String> parameters);
}

class SubjectProxy implements Subject{
    private RealSubject realSubject;
    private String address;
    private HashMap<String, String> parameters;
    int id;

    public SubjectProxy(RealSubject realSubject, String address, HashMap<String, String> parameters, int id){
        this.realSubject = realSubject;
        this.address = address;
        this.parameters = parameters;
        this.id = id;
    }

    @Override
    public void f1() {
        if (realSubject == null){
            // Serverski pozviv
        } else {
            // Lokalni
        }
    }

    @Override
    public void f2() {
        if (realSubject == null){
            // Serverski pozviv
        } else {
            // Lokalni
        }
    }

    @Override
    public int f3() {
        if (realSubject == null){
            // Serverski pozviv
        } else {
            // Lokalni
        }
        return 0;
    }

    @Override
    public int id() {
        if (realSubject == null){
            // Serverski pozviv
        } else {
            // Lokalni
        }
        return 0;
    }
}

public class Solution {
}
