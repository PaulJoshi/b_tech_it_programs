class Circle{
    double r;
    double area() {
        return 3.14 * r * r;
    }
}

class CircleArea{
    public static void main(String args[]) {
        Circle ob1 = new Circle();
        ob1.r = 3;
        System.out.println("Area = " + ob1.area());
    }
}