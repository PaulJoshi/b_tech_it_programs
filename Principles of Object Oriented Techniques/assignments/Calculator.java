class CalculatorClass {

	int a;
	int b;

	CalculatorClass(int a,int b){
		this.a = a;
		this.b = b;
	};

	void add() {	
		int sum = a + b;
		System.out.println("Sum is: " + sum);
	}

	void difference() {
		int difference = a - b;
		System.out.println("Difference is: " + difference);
	}

	void product() {
		int product = a * b;
		System.out.println("Product is: " + product);
	}

	void divide() {
	    try {
		   int c = a / b;
		   System.out.println(c);
		} catch(ArithmeticException e) {
            System.out.println("Exception, changing value of b to 1");
		    b = 1;
		    int c = a / b;
		    System.out.println("Quotient is:" + c);
		}	
	}
}

class Calculate {
	public static void main(String args[]) {
		try {
            String a = args[0];
            String b = args[1];
            String c = args[2];

            int x1 = Integer.parseInt(a);
            int x2 = Integer.parseInt(c);

            CalculatorClass ob = new CalculatorClass(x1, x2);
            
            if(b.equals("+"))
                ob.add();
            if(b.equals("-"))
                ob.difference();
            if(b.equals("x"))
                ob.product();
            if(b.equals("/"))
                ob.divide();
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Enter two values and symbol");
		} 
	}
}