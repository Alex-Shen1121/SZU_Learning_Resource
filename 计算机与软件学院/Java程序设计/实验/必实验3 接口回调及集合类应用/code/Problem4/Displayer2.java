package Exp3_2.Problem4;

public class Displayer2 implements Comparable<Displayer2> {
    int screenSize;
    double price;

    @Override
    public int compareTo(Displayer2 o) {
        return Double.compare(this.price, o.price);
    }

    public Displayer2(int screenSize, double price) {
        this.screenSize = screenSize;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Displayer2{" +
                "screenSize=" + screenSize +
                ", price=" + price +
                '}';
    }
}
