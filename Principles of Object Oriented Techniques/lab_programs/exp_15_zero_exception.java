// Write a program to demonstrate division by zero exception.

class Exception {
    public static void main(String args[]) {
        int a, b = 0, c;
        a = Integer.parseInt(args[0]);
        try {
            c = a / b;
            System.out.println("a / b = " + c);
        } catch(ArithmeticException e) {
            System.out.println("\nException is " + e);
        } finally {
            b = 1; c = a / b;
            System.out.println(a + " / " + b + " = " + c + "\n");
        }
    }
}