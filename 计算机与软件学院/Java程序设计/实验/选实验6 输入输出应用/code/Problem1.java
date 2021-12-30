package Exp6_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem1 {
    public static ArrayList<Map<String, String>> readInfo(String filePath) {
        // 打开文件
        File file = new File(filePath);
        Scanner sc = null;
        ArrayList<Map<String, String>> info = new ArrayList<>();
        // 正则表达式 拆分字符串
        String regex = "(\\w+)/(\\w+):\\s(.+)";
        Pattern p = Pattern.compile(regex);
        try {
            sc = new Scanner(file);
            Map<String, String> temp = new HashMap<>();
            while (sc.hasNext()) {
                try {
                    String str = sc.nextLine();
                    // 遇到空行 说明一段信息获取完毕 加载近ArrayList
                    if (str.equals("")) {
                        info.add(new HashMap<String, String>(temp));
                        temp.clear();
                        continue;
                    }
                    Matcher m = p.matcher(str);
                    // 插入键值对
                    if (m.matches()) {
                        temp.put(m.group(2), m.group(3));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return info;
    }

    public static void createProductFile(ArrayList<Map<String, String>> info, String filePath) {
        File file = new File(filePath);
        try {
            FileWriter output = new FileWriter(file);
            for (Map<String, String> item : info)
                output.write(item.get("productId") + ';' + item.get("title") + ';' + item.get("price") + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void createUserFile(ArrayList<Map<String, String>> info, String filePath) {
        File file = new File(filePath);
        try {
            FileWriter output = new FileWriter(file);
            for (Map<String, String> item : info)
                output.write(item.get("userId") + ';' + item.get("profileName") + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void createScoreFile(ArrayList<Map<String, String>> info, String filePath) {
        // 打开文件
        File file = new File(filePath);
        try {
            // 写入文件
            FileWriter output = new FileWriter(file);
            for (Map<String, String> item : info)
                output.write(item.get("userId") + ';' + item.get("productId") + ';' + item.get("score") + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void createReviewFile(ArrayList<Map<String, String>> info, String filePath) {
        File file = new File(filePath);
        try {
            FileWriter output = new FileWriter(file);
            for (Map<String, String> item : info)
                output.write(item.get("userId") + ';' + item.get("productId") + ';' + item.get("summary") + '\n');
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String filePath = "src/Exp6_1/";
        // 获取所有信息键值对
        ArrayList<Map<String, String>> info = readInfo(filePath + "Jewelry.txt");
        // product.txt
        createProductFile(info, filePath + "product.txt");
        // user.txt
        createUserFile(info, filePath + "user.txt");
        // score.txt
        createScoreFile(info, filePath + "score.txt");
        // review.txt
        createReviewFile(info, filePath + "review.txt");
    }
}
