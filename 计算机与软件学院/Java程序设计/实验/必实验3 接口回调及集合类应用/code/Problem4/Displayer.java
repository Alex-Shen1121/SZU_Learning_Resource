package Exp3_2.Problem4;

public class Displayer {
    int screenSize;
    double price;

    public Displayer(int screenSize, double price) {
        this.screenSize = screenSize;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Displayer{" +
                "screenSize=" + screenSize +
                ", price=" + price +
                '}';
    }
}
