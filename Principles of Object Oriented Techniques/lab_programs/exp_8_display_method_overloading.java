// Develop a Java program to implement functions to display an input integer, string and float values using the concept of method overloading.

import java.util.Scanner;

class DisplayOverload {
    void display(int i) {
        System.out.println("Integer : " + i);
    }

    void display(String s) {
        System.out.println("String : " + s);
    }

    void display(Float f) {
        System.out.println("Float : " + f);
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter an Integer: ");
        int i = input.nextInt();
        System.out.println("Enter a String: ");
        String s = input.next();
        System.out.println("Enter a Float: ");
        Float f = input.nextFloat();

        DisplayOverload disp = new DisplayOverload();

        disp.display(i);
        disp.display(s);
        disp.display(f);

        input.close();
    }
}
