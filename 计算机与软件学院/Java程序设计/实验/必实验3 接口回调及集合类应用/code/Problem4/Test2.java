package Exp3_2.Problem4;

import java.util.Comparator;
import java.util.TreeMap;

public class Test2 {
    public static void main(String[] args) {
        TreeMap<Displayer2, Integer> treeMap = new TreeMap<>();

        treeMap.put(new Displayer2(14, 105), 1);
        treeMap.put(new Displayer2(16, 125), 2);
        treeMap.put(new Displayer2(18, 145), 3);
        treeMap.put(new Displayer2(15, 155), 4);
        treeMap.put(new Displayer2(10, 115), 5);

        for (Displayer2 displayer : treeMap.keySet()) {
            System.out.println(displayer);
        }
    }
}
