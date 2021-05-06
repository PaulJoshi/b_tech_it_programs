class Box{
    double l, h, b;

    void setDimension(double l1, double h1, double b1) {
        l = l1;
        h = h1;
        b = b1;
    }

    void getDimension() {
        System.out.println("length = " + l + "\nHeight = " + h + "\nWidth = " + b);
    }

    double volume() {
        return l*h*b;
    }
}

class BoxDemo4{
    public static void main(String args[]) {
        Box b1 = new Box();
        b1.setDimension(2, 4, 5);
        b1.getDimension();
        double v = b1.volume();
        System.out.println("The volume is " + v + "cm cube");
    }
}