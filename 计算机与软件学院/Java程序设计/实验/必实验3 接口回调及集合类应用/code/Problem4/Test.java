package Exp3_2.Problem4;

import java.util.Comparator;
import java.util.TreeMap;

public class Test {
    public static void main(String[] args) {
        TreeMap<Displayer, Integer> treeMap = new TreeMap<>(new Comparator<Displayer>() {
            @Override
            public int compare(Displayer o1, Displayer o2) {
                return Double.compare(o1.price, o2.price);
            }
        });

        treeMap.put(new Displayer(14, 100), 1);
        treeMap.put(new Displayer(16, 120), 2);
        treeMap.put(new Displayer(18, 140), 3);
        treeMap.put(new Displayer(15, 125), 4);
        treeMap.put(new Displayer(10, 110), 5);

        for (Displayer displayer : treeMap.keySet()) {
            System.out.println(displayer);
        }
    }
}
