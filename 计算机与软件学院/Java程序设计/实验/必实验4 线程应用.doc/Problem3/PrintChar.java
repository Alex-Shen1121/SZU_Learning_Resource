package Exp4_1.Problem3;

public class PrintChar implements Runnable{
    PrintNumberAndChar printNumberAndChar;

    public PrintChar(PrintNumberAndChar printNumberAndChar) {
        this.printNumberAndChar = printNumberAndChar;
    }

    @Override
    public void run() {
        printNumberAndChar.printChar();
    }
}
