package Exp3_2;

import java.util.HashMap;
import java.util.Map;

public class Problem2 {
    public static void main(String[] args) {
        // 创建map集合
        Map<String, Double> menu = new HashMap<String, Double>();
        menu.put("北京烤鸭", 199.1);
        menu.put("西芹炒肉", 12.9);
        menu.put("酸菜鱼", 59.0);
        menu.put("铁板牛柳", 32.1);

        // 遍历map集合并计算总价格
        Double sum = 0.0;
        System.out.println("菜单详情：");
        for (Map.Entry<String, Double> entry : menu.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
            sum += entry.getValue();
        }
        System.out.println("总价格为：" + sum + "元。");

    }
}
