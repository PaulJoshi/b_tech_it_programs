# Class rectangle that has attrubutes length & breadth
# Also write method area() which returns area of the rectangle

class Rectangle :

    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self) :
        return self.length * self.breadth

rectangle_1 = Rectangle(int(input("Enter length: ")), int(input("Enter breadth: ")))

print(f"Area of rectangle is {rectangle_1.area()}")