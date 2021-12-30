package Exp3_2;

import java.util.ArrayList;
import java.util.Objects;

public class Problem3 {
    public static class Student {
        String name;

        public Student(String name) {
            this.name = name;
        }

        @Override
        public String toString() {
            return "Student{" +
                    "name='" + name + '\'' +
                    '}';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Student student = (Student) o;
            return Objects.equals(name, student.name);
        }
    }

    public static void main(String[] args) {
        ArrayList<Student> clubA = new ArrayList<Student>(), clubB = new ArrayList<Student>();
        clubA.add(new Student("张三"));
        clubA.add(new Student("李四"));
        clubA.add(new Student("刘六"));

        clubB.add(new Student("李四"));
        clubB.add(new Student("王五"));
        clubB.add(new Student("刘六"));


        System.out.println("参加A社团的名单:");
        for (Student stu : clubA) {
            System.out.println(stu);
        }

        System.out.println("\n参加B社团的名单:");
        for (Student stu : clubB) {
            System.out.println(stu);
        }

        System.out.println("\n同时参加A社团与B社团的名单:");
        for (Student stu : clubA) {
            if (clubB.contains(stu))
                System.out.println(stu);
        }
    }
}
