## QnA
---

**Q: Is it possible create an object for a class A using, A ob = new A(); if the class contains only parameterized constructor? Justify**

**A:** No, if you overload the default constructor and create objects without parameters then you have to explicitely define a no argument constructor for it to work.
<br/><br/>

**Q: Briefly explain the primitive data types used in Java.**

**A:** Primitive types are the most basic data types in Java. They are boolean, byte, char short, int, long, float and double.
* Numeric primitives: short, int, long, float and double hold only numeric data. Operations associated with such data types are simple arithmetic or comparisons
* Textual primitives: byte and char hold characters. Operations associated are those of textual manipulation . However, they also support arithmetic operations.
* Boolean and null primitives
<br/><br/>

**Q: Explain how access modifiers are used to control the visibility of identifiers.**

**A:** Java provides a number of access modifiers to set access levels for classes, variables, methods, and constructors. The four access levels are:
* Visible to the package, the default. No modifiers are needed.
* Visible to the class only (private).
* Visible to the world (public).
* Visible to the package and all subclasses (protected).
<br/><br/>

**Q: Describe the following statements in Java.**
1. switch and for
2. break and continue

**A:** The switch statement is used to select one of many code blocks to be executed. Value of the expression is compared with the values of each case.
```java
 int number=20;  
//Switch expression  
switch(number) {  
    //Case statements  
    case 10:    
        System.out.println("10");
        break;
    case 20:
        System.out.println("20");
        break;
    case 30:
        System.out.println("30");
        break;
    default:
        System.out.println("Not in 10, 20 or 30");
}
```
The for loop is used to iterate a part of the program several times. If the number of iteration is fixed, it is recommended to use for loop.
```java
for (int i = 0; i < 5; i++) {
  System.out.println(i);
}
```
The break statement can be used to jump out of a loop. This example jumps out of the loop when i is equal to 4:
```java
for (int i = 0; i < 10; i++) {
  if (i == 4) {
    break;
  }
  System.out.println(i);
}
```
The continue statement breaks one iteration, if a specified condition occurs, and continues with the next iteration in the loop. This example skips the value of 4:
```java
for (int i = 0; i < 10; i++) {
  if (i == 4) {
    continue;
  }
  System.out.println(i);
}
```
<br/>

**Q: What is the use of constructor in Java? Give examples.**

**A:** In Java, a constructor is called to allocate memory for the object and to provide default values to the object.
```java
class Bike {
    // default constructor
    Bike() {
        System.out.println("Bike is created");
    }

    public static void main(String args[]) {
        Bike b = new Bike();  // default constructor is called here
    }
}
```
```java
class Student{  
    int id;
    String name;

    Student(int i, String n) {  
        id = i;
        name = n;  
    }  

    void display() {
        System.out.println(id + " " + name);
    }  
   
    public static void main(String args[]) {
        Student s1 = new Student(111, "Karan");
        Student s2 = new Student(222, "Aryan"); 
        s1.display();  
        s2.display();  
   }  
}  
```
<br/>

**Q: With the help of examples, explain how inheritance is implemented in Java.**

**A:** Inheritance is implemented using the extends keyword. 
```java
class Employee {
    float salary = 40000;
}

class Programmer extends Employee {
    int bonus = 10000;
    public static void main(String args[]) {
        Programmer p = new Programmer();
        System.out.println("Programmer salary is:" + p.salary);
        System.out.println("Bonus of Programmer is:" + p.bonus);
    }  
}
```
In the above example, Programmer is the subclass and Employee is the superclass. Programmer's objects can access its own members as well as that of Employee class.