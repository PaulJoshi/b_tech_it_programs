/* Develop a Java program to read and print student’s data using inheritance Class person:
name, age, gender Class student inherits from person: mark1, mark2, mark3, total marks, grade. */

import java.util.Scanner;

class Person {
	String name;
	int age;
	String gender;
    
	Person(String a, int b, String c) {
		name = a;
		age = b;
		gender = c;
	}
}

class Student extends Person {
	double mark1, mark2, mark3, total_marks;
	String grade;

	Student(String a1, int a2, String a3, double a4, double a5, double a6) {
		super(a1, a2, a3);
		mark1 = a4;
		mark2 = a5;
		mark3 = a6;
		total_marks = mark1 + mark2 + mark3;
	}

	double total_marks() {
		return total_marks;
	}

	void grade() {
		double marks = (total_marks / 300) * 100;
		if(marks >= 90.0)
			System.out.println("Grade: A");
		else if(marks >= 80.0)
			System.out.println("Grade: B");
		else if(marks >= 70.0)
			System.out.println("Grade: C");
		else if(marks >= 60.0)
			System.out.println("Grade: D");
		else if(marks >= 50.0)
			System.out.println("Grade: E");
		else
			System.out.println("Fail");
	}

	void display() {
		System.out.println("\nName: " + name);
		System.out.println("Age: " + age);
		System.out.println("Gender: " + gender);
		System.out.println("Total Marks " + total_marks);
		grade();
	}
}

class StudentDemo {
	public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter name: ");
        String name = input.next();
        System.out.println("Enter age: ");
        int age = input.nextInt();
        System.out.println("Enter gender: ");
        String gender = input.next();
        System.out.println("Enter mark a: ");
        double a = input.nextDouble();
        System.out.println("Enter mark b: ");
        double b = input.nextDouble();
        System.out.println("Enter mark c: ");
        double c = input.nextDouble();

		Student ob = new Student(name, age, gender, a, b, c);
		ob.display();

        input.close();
	}
}