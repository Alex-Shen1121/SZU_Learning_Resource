package Exp4_1.Problem3;

public class PrintNum implements Runnable{
    PrintNumberAndChar printNumberAndChar;

    public PrintNum(PrintNumberAndChar printNumberAndChar) {
        this.printNumberAndChar = printNumberAndChar;
    }

    @Override
    public void run() {
        printNumberAndChar.printNum();
    }
}
