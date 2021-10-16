package Exp3_1.Problem7;

public class Vector implements Computable {
    int a1, a2, a3;

    @Override
    public void add(Vector v1) {
        System.out.printf("v1 + v2 = [%d,%d,%d]\n", v1.a1 + a1, v1.a2 + a2, v1.a3 + a3);
    }

    @Override
    public void minus(Vector v1) {
        System.out.printf("v1 - v2 = [%d,%d,%d]\n", a1 - v1.a1, a2 - v1.a2, a3 - v1.a3);
    }

    public Vector(int a1, int a2, int a3) {
        this.a1 = a1;
        this.a2 = a2;
        this.a3 = a3;
    }

    public static void main(String[] args) {
        Vector v1 = new Vector(5, 2, 1), v2 = new Vector(3, -1, 0);
        v1.add(v2);
        v1.minus(v2);
    }
}
