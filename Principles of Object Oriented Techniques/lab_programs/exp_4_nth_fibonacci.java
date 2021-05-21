/* The Fibonacci sequence is defined by the following rule. The first 2 values in the sequence are 1, 1.
Every subsequent value is the sum of the 2 values preceding it.
Develop a Java program that uses both recursive and no recursive functions to print the nth value of the Fibonacci sequence */

class Fibonacci {
	public static void main(String args[]) {
		int n1 = 0, n2 = 1, n3 = 0;
		System.out.println("\n" + n1);
		System.out.println(n2);

		int x = Integer.parseInt(args[0]);

		for(int i = 2; i < x; i++) {
			n3 = n1 + n2;
			System.out.println(n3);
			n1 = n2;
			n2 = n3;
		}
		
		System.out.println("\n" + x + "th value of Fibonacci is: " + n3 + "\n");

		// Recursion

		int nth = 0;
		FibonacciHelper ob = new FibonacciHelper();
		for(int i = 0; i < x; i++) {
		    System.out.println(ob.fib(i));
		}

		System.out.println("\n" + x + "th value of Fibonacci via recursion is: " + nth + "\n");
	}
}

class FibonacciHelper {
	int fib(int num) {
		if(num <= 1)
			return num;
		return fib(num -1) + fib(num - 2);
	}
}