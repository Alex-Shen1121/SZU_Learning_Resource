package Exp2;

public abstract class Vehicle {
    private String type = "车";
    private double maxSpeed;
    private int tireNum;

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public double getMaxSpeed() {
        return maxSpeed;
    }

    public void setMaxSpeed(double maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public int getTireNum() {
        return tireNum;
    }

    public void setTireNum(int tireNum) {
        this.tireNum = tireNum;
    }

    public void print() {
        System.out.println("type = " + type);
        System.out.println("maxSpeed = " + maxSpeed);
        System.out.println("tireNum = " + tireNum);
    }


    public Vehicle(String type, double maxSpeed, int tireNum) {
        this.type = type;
        this.maxSpeed = maxSpeed;
        this.tireNum = tireNum;
    }
}
