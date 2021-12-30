package Exp3_2.Problem1;

public class HumanTest {
    public static void main(String[] args) {
        Human[] array = {
                new Chinese("中国人"),
                new Japanese("日本人"),
                new English("英国人")
        };
        // 遍历集合
        for (Human human : array) {
            human.sayHello();
        }
    }
}
