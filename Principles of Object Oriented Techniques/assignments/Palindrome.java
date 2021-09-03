// Write a program to check whether a string is palindrome or not. The input is to be accepted through command line parameter.

class Palindrome {
    public static void main(String args[]) {
        String a, b = "";
        a = args[0];
        int n = a.length();

        for(int i = n - 1; i >= 0; i--)
            b = b + a.charAt(i);
        
        if(a.equalsIgnoreCase(b))
            System.out.println(a + " is a palindrome.");
        else
            System.out.println(a + " is not a palindrome.");
    }
}
