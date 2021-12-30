package Exp4_1.Problem1;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class AccountWithoutSync {
    private static Account account = new Account();

    public static void main(String[] args) {
        ExecutorService executor = Executors.newCachedThreadPool();

        for (int i = 0; i < 100; i++) {
            executor.execute(new AddPennyTask());
        }

        executor.shutdown();

        while(!executor.isTerminated()){}
        System.out.println("What is balance? "+ account.getBalance());
    }

    private static class  AddPennyTask implements Runnable{
        @Override
        public void run() {
            account.deposit(1);
        }
    }

    public static class Account {
        private int balance = 0;

        public int getBalance() {
            return balance;
        }

        public void deposit(int amount) {
            int newBalance = balance + amount;
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
            }
            balance = newBalance;
        }
    }
}
