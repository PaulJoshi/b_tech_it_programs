/* Construct a Stack Class with proper exception handling mechanisms.
While doing a Pop operation, if the stack is empty then display an error message.
While doing a Push operation, if the stack is full then display corresponding error message. */

import java.util.Scanner;
import java.lang.Exception;

class StackOverflow extends Exception {
    private int details;

    StackOverflow(int a) {
        details = a;
    }

    public String toString() {
        return "Stack Overflow! Top = " + details;
    }
}

class StackUnderflow extends Exception {
    private int details;

    StackUnderflow(int a) {
        details = a;
    }

    public String toString() {
        return "Stack Underflow! Top = " + details;
    }
}

class StackClass {
    int top = -1, size = 10;
    int[] stackArray = new int[size];  

    void push(int s) throws StackOverflow {
        if(top >= size - 1) {
            throw new StackOverflow(top);
        }
        System.out.println("Value pushed is: " + s);
        top += 1;
        stackArray[top] = s;
    }

    void pop() throws StackUnderflow {
        if(top <= 0) {
            throw new StackUnderflow(top);
        }
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
                    try {
                        stackOb1.push(s);
                    } catch(StackOverflow e) {
                        System.out.println("Caught exception: " + e);
                    }
                    break;
                case 2:
                    try {
                        stackOb1.pop();
                    } catch(StackUnderflow e) {
                        System.out.println("Caught exception: " + e);
                    }
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