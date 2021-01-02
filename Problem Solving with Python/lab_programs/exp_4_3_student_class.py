# Create a class student with attributes name, rollno and a method showData() for showing
# the details. Create two instances of the class and call the method for each instance. Develop
# a python program to implement the scenario.

class Student :

    def __init__(self, name, rollno):
        self.name = name
        self.rollno = rollno
    
    def showData(self) :
        print(f"\nStudent Name : {self.name}\nRoll no      : {self.rollno}")

student_1 = Student("Luke", 52)
student_2 = Student("Leia", 53)

student_1.showData()
student_2.showData()