package Exp4_1.Problem4;

import java.util.Random;

public class Bank implements Runnable {
    static int accountSum = 0;

    public synchronized void withdraw(int value) {
        System.out.println(Thread.currentThread().getName() + "正在取款");
        System.out.println("存款金额为" + value + "---当前账户有" + accountSum + "元");
        // 异常情况
        // 1. 取款金额为负数
        if (value < 0) {
            System.out.println("输入为负数，存款失败");
        } else {
            accountSum += value;
            System.out.println("存款成功！---当前账户有" + accountSum + "元\n");
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Random r = new Random();
            // 随机存款0-100元
            int value = r.nextInt(100);
            withdraw(value);
        }
    }

    public static void main(String[] args) {
        Bank bank = new Bank();
        // 多线程存款
        Thread thread1 = new Thread(bank);
        Thread thread2 = new Thread(bank);
        Thread thread3 = new Thread(bank);
        thread1.start();
        thread2.start();
        thread3.start();
    }
}
