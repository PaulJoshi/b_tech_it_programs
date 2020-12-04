

class students:

    def __init__(self, name) :   #to initialise the variables
        self.name = name
        self.marks = []

    def entermarks(self):
        for i in range(3):
            m = int(input("Enter the marks of %s in subject %d : " %(self.name, i+1)))
            self.marks.append(m)
    
    def display(self):
        print(f"{self.name} got {self.marks}")

s1=students("Smitha")    #class instantiation-creating an object called s1
s1.entermarks()          #invoking class method through object
s2=students("Smitha")
s2.entermarks()
s1.display()
s2.display()