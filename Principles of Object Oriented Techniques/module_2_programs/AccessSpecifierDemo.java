class Test {
    int a;
    public int b;
    private int c;

    void setc(int i) {
        c = i;
    }

    int getc() {
        return c;
    }

    int add() {
        return a + b + c;
    }
}

class AccessSpecifierDemo {
    public static void main(String args[]) {
        Test ob = new Test();

        ob.a = 10;
        ob.b = 20;
        ob.setc(30);
        System.out.println("a = " + ob.a + "\nb = " + ob.b + "\nc = " + ob.getc());
        System.out.println("Sum = " + ob.add());
    }
}