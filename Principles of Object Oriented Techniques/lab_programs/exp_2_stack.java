// Develop a program in Java to implement Stack operations using Class.

import java.util.Scanner;

class StackClass {
    int top = -1;
    int[] stackArray = new int[10];  

    void push(int s) {
        System.out.println("Value pushed is: " + s);
        top += 1;
        stackArray[top] = s;
    }

    void pop() {
        System.out.println("Value popped is: " + stackArray[top]);
        top -= 1;
    }

    void display() {
        System.out.println("\nElements in the Stack are: ");
        for(int i = top; i >= 0; i--) {
            System.out.println(stackArray[i]);
        }
    }
}

class Stack {
    public static void main(String args[]) {
        int choice;

        StackClass stackOb1 = new StackClass();
        Scanner input = new Scanner(System.in);

        System.out.println("\n1. Push\n2. Pop\n3. Display\n4. Exit ");

        while(true) {
            System.out.println("\nEnter your choice: ");
            choice = input.nextInt();
            switch(choice) {
                case 1:
                    System.out.println("Enter value to Push: ");
                    int s = input.nextInt();
                    stackOb1.push(s);
                    break;
                case 2:
                    stackOb1.pop();
                    break;
                case 3:
                    stackOb1.display();
                    break;
                case 4:
                    input.close();
                    System.exit(0);
                default:
                    System.out.println("Error");
            }
        }
    }
}