package Exp3_2.Problem1_4;


public class Test {
    public static void main(String[] args) {
        Human[] array = {
                new Chinese(),
                new Japanese(),
                new English()
        };
        for (Human human : array) {
            human.sayHello();
        }
    }
}
