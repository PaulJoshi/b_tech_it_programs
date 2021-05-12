class CommandLineArguments {
    public static void main(String args[]) {
        System.out.println("a = " + args[0] + "\nb = " + args[1] + "\nc = " + args[2]);
        int sum = Integer.parseInt(args[0]) + Integer.parseInt(args[1]) + Integer.parseInt(args[2]);
        System.out.println("Sum = " + sum);
    }
}