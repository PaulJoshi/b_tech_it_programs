class Box {
    double w, h, d;

    Box(double w, double h, double d) {
        this.w = w;
        this.h = h;
        this.d = d;
    }

    Box(Box ob) {
        w = ob.w;
        h = ob.h;
        d = ob.d;
    }

    double volume() {
        return w*h*d;
    }
}

class OverloadConsPassObject {
    public static void main(String args[]) {
        Box ob1 = new Box(10, 20, 30);
        Box ob2 = new Box(ob1);

        System.out.println("Volume of ob1 = " + ob1.volume());
        System.out.println("Volume of ob2 = " + ob2.volume());
    }
}
