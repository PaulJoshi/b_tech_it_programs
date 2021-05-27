// Develop a Java program to implement functions to display an input integer, string and float values using the concept of method overloading.

import java.util.Scanner;

class DisplayOverload {
    DisplayOverload(int i) {
        System.out.println("Integer : " + i);
    }

    DisplayOverload(String i) {
        System.out.println("String : " + i);
    }

    DisplayOverload(Float i) {
        System.out.println("Float : " + i);
    }
}

class Overload {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter an Integer: ");
        int i = input.nextInt();

        System.out.println("Enter a String: ");
        String s = input.next();

        System.out.println("Enter a Float: ");
        Float f = input.nextFloat();

        DisplayOverload displayInt = new DisplayOverload(i);
        DisplayOverload displayStr = new DisplayOverload(s);
        DisplayOverload displayFlo = new DisplayOverload(f);

        input.close();
    }
}