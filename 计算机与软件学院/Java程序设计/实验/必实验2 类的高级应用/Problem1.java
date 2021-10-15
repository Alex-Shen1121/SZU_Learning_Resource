package Exp2;

public class Problem1 {
    public static class Bicycle extends Vehicle {
        private int gearNum;

        public Bicycle(String type, double maxSpeed, int tireNum, int num) {
            super(type, maxSpeed, tireNum);
            this.gearNum = num;
        }

        public int getGearNum() {
            return gearNum;
        }

        public void setGearNum(int gearNum) {
            this.gearNum = gearNum;
        }

        @Override
        public void print() {
            super.print();
            System.out.println("gearNum = " + gearNum);
            System.out.println();
        }
    }

    public static class Car extends Vehicle {
        private String carType;

        public String getCarType() {
            return carType;
        }

        public void setCarType(String carType) {
            this.carType = carType;
        }

        @Override
        public void print() {
            super.print();
            System.out.println("carType = " + carType);
            System.out.println();
        }

        public Car(String type, double maxSpeed, int tireNum, String carType) {
            super(type, maxSpeed, tireNum);
            this.carType = carType;
        }
    }

    public static class Train extends Vehicle {
        private double cargoCapacity;

        public double getCargoCapacity() {
            return cargoCapacity;
        }

        public void setCargoCapacity(double cargoCapacity) {
            this.cargoCapacity = cargoCapacity;
        }

        @Override
        public void print() {
            super.print();
            System.out.println("cargoCapacity = " + cargoCapacity);
            System.out.println();
        }

        public Train(String type, double maxSpeed, int tireNum, double cargoCapacity) {
            super(type, maxSpeed, tireNum);
            this.cargoCapacity = cargoCapacity;
        }
    }

    public static void main(String[] args) {
        Bicycle bicycle = new Bicycle("自行车", 30, 2, 27);
        Car car = new Car("小汽车", 120, 4, "新能源汽车");
        Train train = new Train("火车", 200, 100, 500);
        bicycle.print();
        car.print();
        train.print();
    }
}
