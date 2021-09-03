/* Develop a java program that implements a multi-thread application that has three threads.
First thread generates random integer for every 1 second and if the value is even, second
thread computes the square of the number and prints and if the value is odd, the third
thread will print the value of cube of the number. */

import java.util.Random;

class Square extends Thread {
	int x;
	Square(int n) {
		x = n;
	}
	public void run() {
		System.out.println("Square     : " + x * x);
	}
}

class Cube extends Thread {
	int x;
	Cube(int n) {
		x = n;
	}
	public void run() {
		System.out.println("Cube       : " + x * x * x);
	}
}

class Number extends Thread {
	public synchronized void run() {
		Random obj = new Random();

		for(int i = 0; i < 5; i++) {
			int a = obj.nextInt(100);
			System.out.println("Random num : " + a);
			if(a % 2 == 0) {
				Square ob1 = new Square(a);
				ob1.start();
			} else {
				Cube ob2 = new Cube(a);
				ob2.start();
			}
			try {
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {
				System.out.println("Interrupted e " + e);
			}
		}
	}
}

class RandomNumber {
	public static void main(String args[]) {
		Number p = new Number();
		p.start();
	}
}