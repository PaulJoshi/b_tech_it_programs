class ObjTester {
    int a, b;

    ObjTester(int i, int j) {
        a = i;
        b = j;
    }

    boolean equals(ObjTester o) {
        return (o.a == a && o.b == b);
    }
}

class ObjectParameter {
    public static void main(String args[]) {
        ObjTester ob1 = new ObjTester(100, 200);
        ObjTester ob2 = new ObjTester(100, 200);
        ObjTester ob3 = new ObjTester(-1, -1);

        boolean b1 = ob1.equals(ob2);
        System.out.println("ob1 = ob2 is " + b1);

        b1 = ob1.equals(ob3);
        System.out.println("ob1 = ob3 is " + b1);
    }
}