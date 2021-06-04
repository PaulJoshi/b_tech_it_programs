/* Suppose your institution wishes to maintain a database of its employees. The database is divided into a number of classes whose
(Assistant Professor, Associate Professor,  Professor etc). Construct a Super Class Person to store personal information. Derive all
the above classes from the Class. Develop a Java program to specify all the classes and define functions to create the database and
retrieve individual information as and when required. Support at least 5 employees on each category. */

import java.util.Scanner;

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

class Professor extends Person {
    String dept;
    int emp_id;

    Professor(String name, int age, String dept, int emp_id) {
        super(name, age);
        this.dept = dept;
        this.emp_id = emp_id;
    }

    String getName() {
        return this.name;
    }

    void printDetails() {
        System.out.println(name + "  " + age + "  Professor        " + dept + "  " + emp_id);
    }
}

class AssistantProfessor extends Professor {
    AssistantProfessor(String name, int age, String dept, int emp_id) {
        super(name, age, dept, emp_id);
    }

    void printDetails() {
        System.out.println(name + "  " + age + "  Asst. Professor  " + dept + "  " + emp_id);
    }
}

class AssociateProfessor extends Professor {
    AssociateProfessor(String name, int age, String dept, int emp_id) {
        super(name, age, dept, emp_id);
    }

    void printDetails() {
        System.out.println(name + "  " + age + "  Asso. Professor  " + dept + "  " + emp_id);
    }
}

class Institution {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String name, dept;
        int choice, prof_choice, age, emp_id = 1;
        int prof_count, assi_prof_count, asso_prof_count;
        prof_count = assi_prof_count = asso_prof_count = 0;

        Professor professors[] = new Professor[5];
        AssistantProfessor assistant_professors[] = new AssistantProfessor[5];
        AssociateProfessor associate_professors[] = new AssociateProfessor[5];

        System.out.println("\n1. Add Professor\n2. Search Professors\n3. Display all\n4. Exit");

        while(true) {
            System.out.print("\nEnter your choice: ");
            choice = input.nextInt();

            switch(choice) {
                case 1:
                    System.out.println("\n1. Assistant Professor\n2. Associate Professor\n3. Professor\nEnter position(1, 2, 3): ");
                    prof_choice = input.nextInt();input.nextLine();
                    System.out.println("Enter name: ");
                    name = input.nextLine();
                    System.out.println("Enter age: ");
                    age = input.nextInt();input.nextLine();
                    System.out.println("Enter department: ");
                    dept = input.nextLine();

                    switch(prof_choice) {
                        case 1:
                            assistant_professors[assi_prof_count++] = new AssistantProfessor(name, age, dept, emp_id++);
                            System.out.println("-- Assistant Professor Added --");
                            break;
                        case 2:
                            associate_professors[asso_prof_count++] = new AssociateProfessor(name, age, dept, emp_id++);
                            System.out.println("-- Associate Professor Added --");
                            break;
                        case 3:
                            professors[prof_count++] = new Professor(name, age, dept, emp_id++);
                            System.out.println("-- Professor Added --");
                            break;
                        default:
                            System.out.println("\nPosition choice error");
                    }
                    break;
                case 2:
                    input.nextLine();
                    System.out.println("Enter name: ");
                    name = input.nextLine();

                    System.out.println("\nName   Age   Position   Dept   EmpID\n------------------------------------");

                    for(int i = 0; i < professors.length; i++) {
                        if(professors[i] != null && professors[i].getName().equalsIgnoreCase(name)) {
                            professors[i].printDetails();
                        }
                    }

                    for(int i = 0; i < assistant_professors.length; i++) {
                        if(assistant_professors[i] != null && assistant_professors[i].getName().equalsIgnoreCase(name)) {
                            assistant_professors[i].printDetails();
                        }
                    }

                    for(int i = 0; i < associate_professors.length; i++) {
                        if(associate_professors[i] != null && associate_professors[i].getName().equalsIgnoreCase(name)) {
                            associate_professors[i].printDetails();
                        }
                    }
                    break;
                case 3:
                    System.out.println("\nName   Age   Position   Dept   EmpID\n------------------------------------");

                    for(int i = 0; i < professors.length; i++) {
                        if(professors[i] != null) {
                            professors[i].printDetails();
                        }
                    }

                    for(int i = 0; i < assistant_professors.length; i++) {
                        if(assistant_professors[i] != null) {
                            assistant_professors[i].printDetails();
                        }
                    }

                    for(int i = 0; i < associate_professors.length; i++) {
                        if(associate_professors[i] != null) {
                            associate_professors[i].printDetails();
                        }
                    }
                    break;
                case 4:
                    input.close();
                    System.exit(1);
                default:
                    System.out.println("Input Error");
                    break;
            }
        }
    }
}