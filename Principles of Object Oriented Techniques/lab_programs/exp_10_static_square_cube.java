/* Write a program to read a number as command line argument and
a. Find square of the number using static function
b. Find cube of the number using static function */

class StaticMathHelper {
    public static int square(int x) {
        return x * x;
    }

    public static int cube(int x) {
        return x * x * x;
    }
}
class StaticMath {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);

        System.out.println("\nSquare is " + StaticMathHelper.square(x));
        System.out.println("Cube is " + StaticMathHelper.cube(x));
    }
}
