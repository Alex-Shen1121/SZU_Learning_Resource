package Exp2;

public class Problem2 {
    public static class Person{
        String name;
        double weight;
        double height;

        @Override
        public String toString() {
            return "Person{" +
                    "name='" + name + '\'' +
                    ", weight=" + weight +
                    ", height=" + height +
                    '}';
        }

        public Person(String name, double weight, double height) {
            this.name = name;
            this.weight = weight;
            this.height = height;
        }
    }

    public static void main(String[] args) {
        Person person = new Person("Lisa",50,170);
        System.out.println(person);
    }
}
