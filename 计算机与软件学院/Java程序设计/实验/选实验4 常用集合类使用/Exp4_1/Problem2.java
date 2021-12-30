package Exp4_1;


public class Problem2 {
    public static void main(String[] args) {
        Goods[] goods = {
                new Goods(true, "匕首"),
                new Goods(false, "书本"),
                new Goods(true, "火药")
        };
        Machine machine = new Machine();
        for (Goods good : goods) {
            try {
                machine.checkBag(good);
            } catch (DException e) {
                e.toShow();
            }
        }
    }
}
