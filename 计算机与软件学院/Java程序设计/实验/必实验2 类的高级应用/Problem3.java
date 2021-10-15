package Exp2;

public class Problem3 {
    public static class Queue {
        // 数组
        public float[] elements;
        // 元素数量
        public int size;
        // 最大容量
        public int capacity;

        public Queue() {
            size = 0;
            capacity = 12;
            elements = new float[capacity];
        }

        // 入队列方法
        public void enqueue(float v) {
            // 检查队列容量
            if (size < capacity) {
                elements[size] = v;
                size++;
                System.out.println("插入队列成功");
            } else {
                System.out.println("插入队列失败");
            }
        }

        public float dequeue() {
            // 检查队列容量
            if (size > 0) {
                float val = elements[0];
                // 移动元素
                for (int i = 1; i < size; i++) {
                    elements[i - 1] = elements[i];
                }
                System.out.println("删除元素成功");
                size--;
                return val;
            } else {
                System.out.println("删除元素失败");
                return -1;
            }
        }

        public void print() {
            System.out.printf("队列:");
            for (int i = 0; i < size; i++) {
                System.out.printf(elements[i] + " ");
            }
            System.out.println();
        }
    }


    public static void main(String[] args) {
        Queue que = new Queue();
        for (int i = 0; i < 13; i++) {
            que.enqueue(i);
            que.print();
            System.out.println();
        }
        for (int i = 0; i < 13; i++) {
            System.out.println("删除元素:" + que.dequeue());
            que.print();
            System.out.println();
        }
    }
}
