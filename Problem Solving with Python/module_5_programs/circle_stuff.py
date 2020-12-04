# Program that has a class circle
# Use class variables to define the value of pi
# Use this class variable to find area and circumference of the circle with special

class Circle :
    pi = 3.14

    def __init__(self, radius) :
        self.radius = radius
    
    def area(self) :
        return Circle.pi * (self.radius ** 2)
    
    def circumference(self) :
        return 2 * Circle.pi * self.radius

c = Circle(5.0)
print(f"Area = {c.area()}")
print(f"Circumference = {c.circumference()}")