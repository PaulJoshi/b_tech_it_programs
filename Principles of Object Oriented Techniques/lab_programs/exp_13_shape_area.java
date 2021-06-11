/* Develop a java program to create an abstract class named Shape that contains two integers and an empty method named printArea(). Provide three classes named Rectangle,
Triangle and Circle such that each one of the classes extends the class Shape. Each one of the classes contain only the method printArea( ) that prints the area of the given shape.*/

abstract class Shape {
	int a, b;
	abstract void printArea();
}

class Rectangle extends Shape {
	Rectangle(int x, int y) {
		a = x;
		b = y;
	}

	void printArea() {
		double area = a * b;
		System.out.println("\nArea of the Rectangle is : " + area);
	}
}

class Triangle extends Shape {
	Triangle(int m, int n) {
		a = m;
		b = n;
	}

	void printArea() {
		double area = 0.5 * a * b;
		System.out.println("Area of the Triangle is  : " + area);
	}
}

class Circle extends Shape {	
	Circle(int p) {
		a = p;
	}

	void printArea() {
		double area = 3.14 * a * a;
		System.out.println("Area of the Circle is    : " + area + "\n");
	}
}

class AbstractDemo {
	public static void main(String args[]) {
		Rectangle ob1 = new Rectangle(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
		Triangle ob2 = new Triangle(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
		Circle ob3 = new Circle(Integer.parseInt(args[0]));
		
		ob1.printArea();
		ob2.printArea();
		ob3.printArea();
	}
}