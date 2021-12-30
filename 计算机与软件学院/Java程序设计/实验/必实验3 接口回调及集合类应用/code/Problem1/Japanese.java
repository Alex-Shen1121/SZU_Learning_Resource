package Exp3_2.Problem1;

public class Japanese extends Human {

    public Japanese(String name) {
        super(name);
    }

    @Override
    public void sayHello() {
        System.out.println("こんにちは!");
    }
}
