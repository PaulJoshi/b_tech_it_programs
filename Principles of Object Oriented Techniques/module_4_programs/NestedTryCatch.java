public class NestedTryCatch {
    public static void main(String[] args) {
        try {
            int a = args.length;
            int b = 42 / a;
            System.out.println("a = " + a);

            try {
                if(a == 1)
                    a = a / (a - a);
                if(a == 2) {
                    int c[] = {1};
                    c[20] = 99;
                }
            } catch(ArrayIndexOutOfBoundsException e) {
                System.out.println("ArrayIndexOutofBoundsException" + e);
            }
        } catch(ArithmeticException e) {
            System.out.println("Divide by 0 " + e);
        }
    }
}
