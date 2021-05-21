/* Write a program that creates a class rectangle with instance variables for the length and the breadth.
Initialize and display its variables. Also find the area of rectangle. */

import java.util.Scanner;

class Rectangle {
	int l, b;
	
	void set_var(int l, int b) {
		this.l = l;
		this.b = b;
	}

	void get_var() {
		System.out.println("\nLength is: " + l);
		System.out.println("Breadth is: " + b);
	}

	void area() {
		System.out.println("Area is: " + l * b + "\n");
	}
}

class RectArea {
	public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
		Rectangle ob = new Rectangle();

        System.out.println("\nEnter length: ");
        int l = input.nextInt();
        System.out.println("Enter breadth: ");
        int b = input.nextInt();
		ob.set_var(l, b);
		ob.get_var();
		ob.area();
	}
}