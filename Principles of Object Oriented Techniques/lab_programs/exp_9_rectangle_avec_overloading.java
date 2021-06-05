/* Write a program that creates a class rectangle with instance variables for the length and the breadth. Initialize and display its variables.
Use constructor overloading to initialize variables. First constructor is without argument (Set a default value here). Second constructor is
with one argument (In this case make it a square) Third constructor is with two arguments. Also find the area of rectangle. */

import java.util.Scanner;

class Rectangle {
    int length, breadth;

    Rectangle() {
        length = 3;
        breadth = 4;
    }

    Rectangle(int x) {
        length = x;
        breadth = x;
    }

    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Rectangle rect_no_args = new Rectangle();
        System.out.println("\nArea of rectangle with no arguments is: " + rect_no_args.area());

        System.out.println("\nEnter square length: ");
        int x = input.nextInt();
        Rectangle square = new Rectangle(x);
        System.out.println("Area of square is: " + square.area());

        System.out.println("\nEnter rectangle length: ");
        int l = input.nextInt();
        System.out.println("Enter rectangle breadth: ");
        int b = input.nextInt();
        Rectangle rect = new Rectangle(l, b);
        System.out.println("Area of rectangle is: " + rect.area());

        input.close();
    }
}