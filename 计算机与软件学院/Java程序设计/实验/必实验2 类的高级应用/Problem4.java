package Exp2;

import java.util.Random;
import java.util.Scanner;

public class Problem4 {
    public static class StopWatch {
        private long startTime, endTime;

        public void start() {
            startTime = System.currentTimeMillis();
        }

        public void end() {
            endTime = System.currentTimeMillis();
            System.out.println("总计用时:" + (endTime - startTime) + "ms");
        }
    }

    public static void quickSort(int[] arr, int low, int high) {
        int p, i, j, temp;
        if (low >= high) {
            return;
        }
        //p就是基准数,这里就是每个数组的第一个
        p = arr[low];
        i = low;
        j = high;
        while (i < j) {
            //右边当发现小于p的值时停止循环
            while (arr[j] >= p && i < j) {
                j--;
            }
            //这里一定是右边开始，上下这两个循环不能调换
            //左边当发现大于p的值时停止循环
            while (arr[i] <= p && i < j) {
                i++;
            }
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        arr[low] = arr[i];//这里的arr[i]一定是停小于p的，经过i、j交换后i处的值一定是小于p的(j先走)
        arr[i] = p;
        quickSort(arr, low, j - 1);  //对左边快排
        quickSort(arr, j + 1, high); //对右边快排
    }

    public static void printArray(int[] array) {
        for (int val : array) {
            System.out.print(val + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {
        StopWatch clock = new StopWatch();

        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        System.out.println("正确性测试：");
        int[] testArray = new int[10];
        for (int j = 0; j < 10; j++) {
            testArray[j] = random.nextInt(10);
        }
        printArray(testArray);
        quickSort(testArray, 0, 9);
        printArray(testArray);

        // 测试数据为100w——1000w
        for (int size = 0; size <= 10000000; size += 1000000) {
            int[] array = new int[size];
            for (int j = 0; j < size; j++) {
                array[j] = random.nextInt(size);
            }
            clock.start();
            quickSort(array, 0, size - 1);
            System.out.print("size = " + size + "  ");
            clock.end();
        }
    }
}
