package Exp4_1.Problem2;

public class OddTester implements Runnable {
    private Pipe pipe;

    public OddTester(Pipe pipe) {
        this.pipe = pipe;
        new Thread(this).start();
    }

    boolean isOdd(int value) {
        return value % 2 == 1;
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if (pipe.isEmpty())
                continue;
            int value = pipe.Front();
            System.out.println(Thread.currentThread().getName() + " check " + value + " is odd: " + isOdd(value));
        }
    }
}
