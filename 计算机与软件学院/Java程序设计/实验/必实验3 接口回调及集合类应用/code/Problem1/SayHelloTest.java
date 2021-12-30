package Exp3_2.Problem1;

public class SayHelloTest {
    public static void main(String[] args) {
        Human human = new Chinese("中国人");
        human.sayHello();
        human = new Japanese("日本人");
        human.sayHello();
        human = new English("英国人");
        human.sayHello();
    }
}
