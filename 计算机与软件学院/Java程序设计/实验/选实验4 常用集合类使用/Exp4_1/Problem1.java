package Exp4_1;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

import static java.lang.Math.abs;

public class Problem1 {
    public static void main(String[] args) {
        Date[] dates = new Date[5];
        System.out.println("请输入5个日期：（格式：××××年××月××日××时）");
        for (int i = 0; i < 5; i++) {
            Scanner sc = new Scanner(System.in);
            // 定义日期格式化
            SimpleDateFormat ft = new SimpleDateFormat("yyyy年MM月dd日HH时");
            try {
                dates[i] = ft.parse(sc.nextLine());
            } catch (ParseException e) {
                // 如果输入不合法 重新输入
                i--;
                System.out.println("非法输入，请重新输入。");
            }
//            2021年10月28日21时
//            2021年10月28日18时
//            2021年10月28日20时
//            2021年9月28日18时
//            2020年10月28日21时
        }
        for (int i = 1; i < 5; i++) {
            // 利用时间戳计算时差
            long nh = 1000 * 60 * 60;
            long nd = 1000 * 24 * 60 * 60;
            // 计算相邻日期的时间戳差值
            long diff = abs(dates[i - 1].getTime() - dates[i].getTime());
            long hour = diff % nd / nh;
            System.out.printf("%tF %tR 与 %tF %tR ", dates[i - 1], dates[i - 1], dates[i], dates[i]);
            System.out.printf("相差%d小时\n", hour);
        }
    }
}
