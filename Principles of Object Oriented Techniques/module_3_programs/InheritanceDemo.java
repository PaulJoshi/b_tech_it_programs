class A {
	int i;
	int j;
	void showij() {
		System.out.println("i = " + i + "  j = " + j);
    }
}
class B extends A {
	int k;
	void showk() {
		System.out.println("k =  "+ k);
	}
	void sum() {
		int total = i + j + k;
		System.out.println("Sum = " + total);
	}
}
class InheritanceDemo {
	public static void main(String args[]){
		A superOb = new A();
		B subOb = new B();
		superOb.i = 10;
		superOb.j = 20;
		superOb.showij();
		
		subOb.i = 1;
		subOb.j = 2;
		subOb.k = 3;
		subOb.showij();
		subOb.showk();
		subOb.sum();
	}
}