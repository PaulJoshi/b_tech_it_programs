// Define a Java class having overloaded methods to calculate area of rectangle and circle.

class Overload {
    void area(double x, double y) {
        System.out.println("Area of the rectangle is " + x * y + " sq units");
    }

    void area(double x) {
        double z = 3.14 * x * x;
        System.out.println("Area of the circle is " + z + " sq units");
    }
}

class AreaMethodOverload {
    public static void main(String args[]) {
        Overload ob = new Overload();
        ob.area(2.4, 3.2);
        ob.area(2.5);
    }
}
