/* Write a program that creates a class rectangle with instance variables for the length and the breadth.
Initialize and display its variables. Use constructor to initialize variables.
Also find the area of rectangle. */

import java.util.Scanner;

class Rectangle {
	int l, b;
	
	Rectangle(int l, int b) {   //constructor
		this.l = l;
		this.b = b;
	}

	void get_var() {
		System.out.println("\nLength is: " + l);
		System.out.println("Breadth is: " + b);
	}

	void area() {
		int area = l * b;
		System.out.println("Area is: " + area + "\n");
	}
}

class RectArea2 {
	public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        System.out.println("\nEnter length: ");
        int l = input.nextInt();
        System.out.println("Enter breadth: ");
        int b = input.nextInt();

		Rectangle ob = new Rectangle(l, b);
		ob.get_var();
		ob.area();
	}
}