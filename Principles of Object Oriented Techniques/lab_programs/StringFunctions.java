public class StringFunctions {
	public static void main(String args[])
	{
		char charList1[] = {'P','a','u','l'};
		char charList2[] = {'j','o','s','h','i'};

		String s1 = new String(charList1);
		String s2 = new String(charList2);
		String s3 = "        Hello World!";

		System.out.println("\nString S1 : " + s1);
		System.out.println("String S2 : " + s2);
		System.out.println("\nLength Function              - Length of S1             : " + s1.length());
		System.out.println("String Concatenation         - S1 + S2                  : " + s1 + " " + s2);
		System.out.println("Concat with other data types - 2 + 2                    : " + 2 + 2);
		System.out.println("CharAt Function              - Get char in s2 at 1      : " + s2.charAt(1));
		System.out.println("equals Function              - Compare S1 and S2        : " + s1 + " = " + s2 + " -> " + s1.equals(s2));
		System.out.println("indexOf Function             - 'l' is at                : " + s1.indexOf('l'));
		System.out.println("substring Function           - from 1                   : " + s1.substring(1));
		System.out.println("replace Function             - Replace u with m         : " + s1.replace('u','m'));
		System.out.println("toLowerCase Function         - Convert S1 to Lowercase  : " + s1.toLowerCase());
		System.out.println("toUpperCase Function         - Convert S1 to Uppercase  : " + s1.toUpperCase());
		System.out.println("trim function                - \"        Hello World!\"   : " + s3.trim() + "\n");
	}
}
