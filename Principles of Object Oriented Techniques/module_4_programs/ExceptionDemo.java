class Exception {
    public static void main(String args[]) {
        int a, b, c;
        a = 10;
        b = 0;
        try {
            c = a/b;
            System.out.println("a / b = " + c);
        } catch(ArithmeticException e) {
            System.out.println("Exception is " + e);
        } finally {
            b = 1; c = a / b;
            System.out.println(" c = " + c);
        }
    }
}