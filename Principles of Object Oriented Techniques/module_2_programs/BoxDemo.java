class Box{
    double w;
    double h;
    double d;
}

class BoxDemo{
    public static void main(String args[]) {
        Box object = new Box();
        object.w = 2;
        object.h = 3;
        object.d = 5;
        double vol = object.w*object.h*object.d;
        System.out.println(vol);
    }
}