package Exp3_1.Porblem6;

public class Animal {
    public void run() {
        System.out.println("Animal类中调用run()");
    }

    public void eat() {
        System.out.println("Animal类中调用eat()");
    }

    public void test() {
        run();
        eat();
        System.out.println();
    }
}
