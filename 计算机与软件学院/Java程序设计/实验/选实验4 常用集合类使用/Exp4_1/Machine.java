package Exp4_1;

public class Machine {
    public void checkBag(Goods goods) throws DException{
        if(goods.isDanger())
            // 如果危险 则抛出异常
            throw new DException();
        else
            System.out.println("正常物品");
    }
}
