package Exp6_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem2 {

    public static void main(String[] args) {
        // 打开文件
        String filePath = "src/Exp6_1/";
        File file = new File(filePath + "score.txt");
        Scanner sc = null;
        HashMap<String, ArrayList<Double>> productAvgInfo = new HashMap<>();
        HashMap<String, ArrayList<Double>> userAvgInfo = new HashMap<>();
        // 正则表达式 根据分号拆分
        String regex = "(.+);(.+);(.+)";
        Pattern p = Pattern.compile(regex);
        try {
            sc = new Scanner(file);
            while (sc.hasNext()) {
                try {
                    String str = sc.nextLine();
                    Matcher m = p.matcher(str);
                    if (m.matches()) {
                        // 如果已存在key值，则列表更新
                        if (productAvgInfo.containsKey(m.group(2)))
                            productAvgInfo.get(m.group(2)).add(Double.parseDouble(m.group(3)));
                        // 如果未存在key值，则创建新列表
                        else productAvgInfo.put(m.group(2), new ArrayList<Double>() {{
                            add(Double.parseDouble(m.group(3)));
                        }});

                        if (userAvgInfo.containsKey(m.group(1)))
                            userAvgInfo.get(m.group(1)).add(Double.parseDouble(m.group(3)));
                        else userAvgInfo.put(m.group(1), new ArrayList<Double>() {{
                            add(Double.parseDouble(m.group(3)));
                        }});
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        try {
            FileWriter output = new FileWriter(filePath + "productAvg.txt");
            for (String str : productAvgInfo.keySet())
                output.write(str + ';' + productAvgInfo.get(str).stream().mapToDouble(a -> a).average().getAsDouble() + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileWriter output = new FileWriter(filePath + "userAvg.txt");
            for (String str : userAvgInfo.keySet())
                output.write(str + ';' + userAvgInfo.get(str).stream().mapToDouble(a -> a).average().getAsDouble() + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
