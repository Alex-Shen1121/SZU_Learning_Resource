package Exp4_1;

public class Goods {
    private final boolean isDanger;
    private final String name;

    public boolean isDanger() {
        return isDanger;
    }

    public String getName() {
        return name;
    }

    public Goods(boolean isDanger, String name) {
        this.isDanger = isDanger;
        this.name = name;
    }
}
