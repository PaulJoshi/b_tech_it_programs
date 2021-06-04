// Write a java program to check whether a given number is prime or not.

class PrimeOrNot {
    public static void main(String[] args) {
        int num = Integer.parseInt(args[0]);
        boolean flag = false;

        for(int i = 2; i <= num/2; i++) {
            if (num % i == 0) {
                flag = true;
                break;
            }
        }

        if(num == 0 || num == 1)
            System.out.println(num + " is not prime");
        else if(!flag)
            System.out.println(num + " is prime");
        else
            System.out.println(num + " is not prime");
    }
}
