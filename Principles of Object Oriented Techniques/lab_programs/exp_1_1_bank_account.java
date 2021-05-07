// Develop a program in Java to display the details of bank account using Class.

import java.util.Scanner;

class BankAccount {
    int accountBal = 0;

    void deposit() {
       System.out.println("Enter amount to Deposit: ");
       Scanner input = new Scanner(System.in);
       int depoAmt = input.nextInt();
       accountBal += depoAmt;
       System.out.println("You have deposited:" + depoAmt);
    }

    void withdraw(int withAmt) {
       if(withAmt < accountBal) {
           accountBal -= withAmt;
           System.out.println("You have withdrawn:" + withAmt);
       }
       else {
           System.out.println("Insufficent Balance");
       }
    }

    void accBal() {
        System.out.println("\nAccount balance: " + accountBal);
    }
}

class Bank {
    public static void main(String args[]) {

        BankAccount object = new BankAccount();
        Scanner input = new Scanner(System.in);
        
        System.out.println("\n1. Deposit Cash\n2. Withdraw Cash\n3. View Account Balance\n4. Exit ");

        while(true) {
            System.out.println("\nEnter your choice: ");
            int choice = input.nextInt();
            
            switch(choice) {
                case 1:
                    object.deposit();
                    break;
                case 2:
                    System.out.println("Enter amount to Withdraw: ");
                    int withAmt = input.nextInt();
                    object.withdraw(withAmt);
                    break;
                case 3:
                    object.accBal();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Error");
            }
        }
    }
}