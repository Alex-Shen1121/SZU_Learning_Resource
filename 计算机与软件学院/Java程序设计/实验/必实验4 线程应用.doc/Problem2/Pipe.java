package Exp4_1.Problem2;

import Exp4_1.Problem1.PrintChar;

import java.util.LinkedList;

public class Pipe {
    private LinkedList<Integer> queue = new LinkedList<>();

    public synchronized int Front(){
        return queue.getFirst();
    }

    public boolean isEmpty(){
        return queue.isEmpty();
    }

    public synchronized int Pop(){
        // 异常处理
        if (isEmpty()){
            try {
                throw new Exception();
            }catch (Exception e){
                e.printStackTrace();
            }
        }
        return queue.removeFirst();
    }

    public synchronized void Push(int value){
        queue.push(value);
    }

    public static void main(String[] args) {
        Pipe pipe = new Pipe();
        CreateRandomNumber createRandomNumber = new CreateRandomNumber(pipe);
        OddTester oddTester = new OddTester(pipe);
    }
}
