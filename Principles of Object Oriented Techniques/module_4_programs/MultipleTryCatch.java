class MultipleTryCatch {
    public static void main(String[] args) {
        int a = args.length;
        try {
            int s = 42 / a;
            System.out.println(s);
            int c[] = {1};
            c[10] = 99;
        } catch(ArithmeticException e) {
            System.out.println("Divide by zero " + e);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index error " + e);
        }
        System.out.println("After try catch block");
    }
}
