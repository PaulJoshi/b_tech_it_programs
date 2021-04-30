class Box{
    double w;
    double h;
    double d;

    void setDimension(double w1, double h1, double d1) {
        w = w1;
        h = h1;
        d = d1;
    }

    double volume() {
        double vol;
        vol = w*h*d;
        return vol;
    }

    void getDimension() {
        System.out.println("Width = " + w);
        System.out.println("Height = " + h);
        System.out.println("Depth = " + d);
    }
}

class BoxDemo4{
    public static void main(String args[]) {
        Box object = new Box();
        object.setDimension(1, 2, 3);
        object.getDimension();
        double v = object.volume();
        System.out.println("The volume is " + v + "cm cube");
    }
}