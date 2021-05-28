// Write an application that accepts one command line argument; display the line of reporting if number is positive or negative.

class CommandLineArg {
	public static void main(String args[]) {

		int x = Integer.parseInt(args[0]);

		if(x >= 0)
			System.out.println("\nThe number is positive\n");
		else
			System.out.println("\nThe number is negative\n");
	}
}