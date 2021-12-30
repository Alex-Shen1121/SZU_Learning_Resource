package Exp4_1.Problem1;

public class TaskThreadDemo {
    public static void main(String[] args) {
        Runnable printA = new PrintChar('a',1000);
        Runnable printB = new PrintChar('b', 1000);
        Runnable print100 = new PrintNum(100);

        Thread thread1 = new Thread(printA);
        Thread thread2 = new Thread(printB);
        Thread thread3 = new Thread(print100);

        thread1.start();
        thread2.start();
        thread3.start();
    }
}
