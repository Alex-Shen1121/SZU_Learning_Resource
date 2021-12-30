package Exp4_1.Problem2;

import java.util.Random;

public class CreateRandomNumber implements Runnable {
    private Pipe pipe;

    public CreateRandomNumber(Pipe pipe) {
        this.pipe = pipe;
        new Thread(this).start();
    }

    Random r = new Random();

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            // 生成1-100的随机数
            int value = Math.abs(r.nextInt()) % 100 + 1;
            pipe.Push(value);
            System.out.println(Thread.currentThread().getName() + " create " + value);
        }
    }
}
