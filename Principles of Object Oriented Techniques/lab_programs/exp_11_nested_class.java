// Implementation using inner classes: Write a program to initialise a number, use outer class. To check whether the number is even or odd use inner class.

import java.util.Scanner;

class TestClass {
    int a;

    TestClass(int a) {
        this.a = a;
    }

    void test() {
        TestNestedClass inner = new TestNestedClass();
        inner.display();
    }

    class TestNestedClass {
        void display() {
            if(a % 2 == 0)
                System.out.println(a + " is even\n");
            else
                System.out.println(a + " is odd\n");
        }
    }
}

class Demo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int a = input.nextInt();

        TestClass object = new TestClass(a);
        object.test();

        input.close();
    }
}
