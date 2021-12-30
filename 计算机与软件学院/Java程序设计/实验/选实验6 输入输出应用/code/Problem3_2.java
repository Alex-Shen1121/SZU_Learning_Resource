package Exp6_1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static Exp6_1.Problem1.readInfo;

public class Problem3_2 {
    public static void main(String[] args) {
        String filePath = "src/Exp6_1/";
        // 获取所有信息键值对
        ArrayList<Map<String, String>> info = readInfo(filePath + "Jewelry.txt");
        HashMap<String, ArrayList<Double>> userAvgInfo = new HashMap<>();
        String regex = "(\\d+)/(\\d+)";
        Pattern p = Pattern.compile(regex);
        double sum = 0, cnt = 0;
        for (Map<String, String> item : info) {
            String help = item.get("helpfulness");
            Matcher m = p.matcher(help);
            if (m.matches()) {
                // 去除分母为零的情况
                if (Objects.equals(m.group(2), "0")) continue;
                sum += Double.parseDouble(m.group(1)) / Double.parseDouble(m.group(2));
                cnt++;
            }
        }
        System.out.println("平均帮助度:" + sum / cnt);

    }
}
