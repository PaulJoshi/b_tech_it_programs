class CallByReferenceTest {
    int a, b;

    CallByReferenceTest(int a, int b) {
        this.a = a;
        this.b = b;
    }

    void meth(CallByReferenceTest ob) {
        ob.a *= 2;
        ob.b /= 2;
    }
}

class CallByReference {
    public static void main(String args[]) {
        CallByReferenceTest ob = new CallByReferenceTest(15, 20);

        System.out.println("ob.a = " + ob.a + " ob.b = " + ob.b);

        ob.meth(ob);
        System.out.println("\nAfter calling by reference:\nob.a = " + ob.a + " ob.b = " + ob.b + "\n");
    }
}