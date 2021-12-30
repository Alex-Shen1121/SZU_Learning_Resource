package Exp6_1;

import java.util.*;

import static Exp6_1.Problem1.readInfo;

public class Problem3 {
    public static void main(String[] args) {
        String filePath = "src/Exp6_1/";
        // 获取所有信息键值对
        HashMap<String, Integer> summaryCnt = new HashMap<>();
        HashMap<String, Integer> textCnt = new HashMap<>();
        ArrayList<Map<String, String>> info = readInfo(filePath + "Jewelry.txt");
        for (Map<String, String> item : info) {
            String str = item.get("summary");
            String[] strlist = str.split("[^\\w]");
            for (String temp : strlist) {
                if (Objects.equals(temp, " ") || Objects.equals(temp, "")) continue;
                if (summaryCnt.containsKey(temp)) summaryCnt.put(temp, summaryCnt.get(temp) + 1);
                else summaryCnt.put(temp, 1);
            }
        }
        //这里将map.entrySet()转换成list
        List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(summaryCnt.entrySet());
        //然后通过比较器来实现排序
        list.sort(new Comparator<Map.Entry<String, Integer>>() {
            //降序排序
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });
        System.out.println("summary单词统计:");
        for (int i = 0; i < 10; i++) {
            System.out.println(list.get(i));
        }

        for (Map<String, String> item : info) {
            String str = item.get("text");
            String[] strlist = str.split("[^\\w]");
            for (String temp : strlist) {
                if (Objects.equals(temp, " ") || Objects.equals(temp, "")) continue;
                if (textCnt.containsKey(temp)) textCnt.put(temp, textCnt.get(temp) + 1);
                else textCnt.put(temp, 1);
            }
        }
        //这里将map.entrySet()转换成list
        List<Map.Entry<String, Integer>> list2 = new ArrayList<Map.Entry<String, Integer>>(textCnt.entrySet());
        //然后通过比较器来实现排序
        list2.sort(new Comparator<Map.Entry<String, Integer>>() {
            //降序排序
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });
        System.out.println("text单词统计:");
        for (int i = 0; i < 10; i++) {
            System.out.println(list2.get(i));
        }
    }
}
