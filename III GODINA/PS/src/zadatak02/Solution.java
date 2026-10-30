package zadatak02;

import java.util.HashMap;

class HashSingleton{
    private static HashMap<String, HashSingleton> map = new HashMap<>();
    private String name;
    private HashSingleton(String name){
        this.name = name;
    }

    public static HashSingleton getInstance(String name){
        if (!map.containsKey(name)) {
            map.put(name, new HashSingleton(name));
        }

        return map.get(name);
    }

    public void description(){
        System.out.println(name);
    }
}

public class Solution {
    static void main() {
        HashSingleton a = HashSingleton.getInstance("A");
        HashSingleton b = HashSingleton.getInstance("B");

        a.description();
        b.description();
    }
}
