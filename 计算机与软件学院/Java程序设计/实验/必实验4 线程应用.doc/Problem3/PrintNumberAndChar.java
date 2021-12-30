package Exp4_1.Problem3;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class PrintNumberAndChar {
    Lock lock = new ReentrantLock();
    static char ch = 'A';
    static int num = 1;
    boolean flag = true;    // true->输出Char false->输出Number
    Condition numCondition = lock.newCondition();
    Condition charCondition = lock.newCondition();

    public void printNum() {
        lock.lock();
        while (num <= 26) {
            while (!flag) {   // char没输出玩，则进行等待
                try {
                    numCondition.await();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            // char输出完，则进行输出num
            if (num <= 26) {
                System.out.print(num++);
            }
            flag = false;

            // 唤醒printChar的进程
            charCondition.signal();
        }
        lock.unlock();
    }

    public void printChar() {
        lock.lock();
        while (ch <= 'Z') {
            while (flag) {   // num没输出玩，则进行等待
                try {
                    charCondition.await();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            // num输出完，则进行输出char
            if (ch <= 'Z')
                System.out.print(ch++);

            flag = true;

            // 唤醒printNum的进程
            numCondition.signal();
        }

        lock.unlock();
    }
}
