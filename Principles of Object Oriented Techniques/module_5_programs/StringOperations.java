class StringOperations {
	public static void main(String args[]) {
		char c[] = {'J','a','v','a'};

		String s1 = new String(c);
		System.out.println(s1);
		String s2 = new String(s1);
		System.out.println(s2);
		String s3 = new String(c,1,2);
		System.out.println(s3);
		String s4 = new String();
		System.out.println("This is the empty string" + s4);
		
		int len = s1.length();
		System.out.println("The length of s1 = " + len);
		System.out.println("------------------------");
		String s5 = "abc";
		System.out.println("Length of " + s5 + " is " + s5.length());
		System.out.println("------------------------");
		System.out.println("four " + 2 + 2);
		System.out.println("four " + (2 + 2));
	}
}
