class ToStringDemo {
	public static void main(String args[]) {
		Integer a = 2;
		Integer b = 3;
		String s1 = a.toString();
		String s2 = b.toString();
		
		System.out.println("Four " + a + b);
		System.out.println("Four " + (a + b));
		System.out.println("Four  " + s1 + s2);
		System.out.println("Four  " + (s1 + s2));
	}
}
