class A {
    int i;
}

class B extends A {
    int i;
    B(int a, int b) {
        super.i = a;
        i = b;
    }

    void show() {
        System.out.println("i in class A - baseclass is: " + super.i);
        System.out.println("i in class B - subclass is: " + i);
    }
}

class SecondSuper {
    public static void main(String[] args) {
        B subOb = new B(1, 2);
        subOb.show();
    }
}