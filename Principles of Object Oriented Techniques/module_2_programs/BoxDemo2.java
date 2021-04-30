class Box{
    double w;
    double h;
    double d;
    void volume() {
        double vol;
        vol = w*h*d;
        System.out.println(vol);
    }
}

class BoxDemo2{
    public static void main(String args[]) {
        Box object = new Box();
        object.w = 2;
        object.h = 3;
        object.d = 5;
        object.volume();
    }
}