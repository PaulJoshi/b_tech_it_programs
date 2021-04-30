class Box{
    double w;
    double h;
    double d;
    double volume() {
        double vol;
        vol = w*h*d;
        return vol;
    }
}

class BoxDemo3{
    public static void main(String args[]) {
        Box object = new Box();
        object.w = 2;
        object.h = 3;
        object.d = 5;
        double v = object.volume();
        System.out.println(v);
    }
}