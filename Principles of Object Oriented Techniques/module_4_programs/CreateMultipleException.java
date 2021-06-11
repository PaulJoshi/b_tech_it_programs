// This program creates a custom exception type.

class MyException extends Exception {
	private int detail;

	MyException(int a) {
		detail = a;
	}
	public String toString() {
		return "MyException[" + detail + "]";
	}
}

class DivideByOneException extends Exception {
	private int detail;

	DivideByOneException(int a) {
		detail = a;
	}

	public String toString() {
		return "DivideByOneException[" + detail + "]";
	}
}

class Number{
	int a,b;

	Number(int a,int b) {
		this.a = a;
		this.b = b;
	}

	void divide() throws MyException, DivideByOneException {
		if(a > 10)
			throw new MyException(a);

		if(a == 1)
			throw new DivideByOneException(a);

		System.out.println("Normal exit");
		System.out.println("b/a  = " + b / a);
	}
}
	
class CreateMultipleException {
	static void compute(int a) throws MyException {
		System.out.println("Called compute(" + a + ")");
		if(a > 10)
			throw new MyException(a);
	}

	public static void main(String args[]) {
		Number ob1 = new Number(1, 2);
		try {
			compute(1);
			ob1.divide();
			//compute(20);
		} catch (MyException e) {
			System.out.println("Caught " + e);
		} catch (DivideByOneException e) {
			System.out.println("Caught " + e);
		}
	}
}