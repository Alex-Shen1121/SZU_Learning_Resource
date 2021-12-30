package Exp4_1.Problem3;

public class Test {
    public static void main(String[] args) {
        PrintNumberAndChar printNumberAndChar = new PrintNumberAndChar();
        Thread thread1 = new Thread(new PrintNum(printNumberAndChar));
        Thread thread2 = new Thread(new PrintChar(printNumberAndChar));

        thread1.start();
        thread2.start();
    }
}
