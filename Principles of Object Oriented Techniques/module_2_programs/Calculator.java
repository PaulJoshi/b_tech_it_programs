class Utilities {

    double a, b;

    Utilities(double a, double b) {
        this.a = a;
        this.b = b;
    }

    double add() {
        return a + b;
    }

    double subtract() {
        return a - b;
    }

    double multiply() {
        return a * b;
    }

    double divide() {
        return a / b;
    }

    double power() {
        double power = 1;
        for(double i = 0; i < b; i++)
            power *= a;
        return power;
    }
}

public class Calculator {
    public static void main(String args[]) {

        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[2]);

        Utilities ob = new Utilities(a, b);

        switch(args[1]) {
            case "+":
                System.out.println("\nSum is: " + ob.add() + "\n");
                break;
            case "-":
                System.out.println("\nDifference is: " + ob.subtract() + "\n");
                break;
            case "*":
                System.out.println("\nProduct is: " + ob.multiply() + "\n");
                break;
            case "/":
                System.out.println("\nQuotient is: " + ob.divide() + "\n");
                break;
            case "^":
                System.out.println("\nPower is: " + ob.power() + "\n");
                break;
            default:
                System.exit(0);
        }
    }
}
