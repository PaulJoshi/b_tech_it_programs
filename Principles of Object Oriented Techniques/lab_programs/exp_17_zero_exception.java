// Write a program to demonstrate division by zero exception.

class Divide {
    public static void main(String args[]) {
        int a, b, c;
        a = Integer.parseInt(args[0]);
        b = Integer.parseInt(args[1]);
        try {
            c = a / b;
            System.out.println("a / b = " + c);
        } catch(ArithmeticException e) {
            System.out.println("\nException is " + e);
        } finally {
            System.out.println("Exiting...");
        }
    }
}