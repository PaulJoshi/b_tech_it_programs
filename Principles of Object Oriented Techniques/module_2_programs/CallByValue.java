class CallByValueTest {
    void meth(int i, int j) {
        i *= 2;
        j /= 2;
    }
}

class CallByValue {
    public static void main(String args[]) {
        CallByValueTest ob = new CallByValueTest();

        int a = 15, b = 20;
        System.out.println("a = " + a + " b = " + b);

        ob.meth(a, b);
        System.out.println("\nAfter calling by value:\na = " + a + " b = " + b + "\n");
    }
}
