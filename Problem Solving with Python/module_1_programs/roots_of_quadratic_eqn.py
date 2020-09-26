#Program to calculate roots of a quadratic equation

a = int(input("Enter coefficient of a: "))
b = int(input("Enter coefficient of b: "))
c = int(input("Enter coefficient of c: "))

print(f"\nQuadratic Equation is {a}x^2 + {b}x + {c}")

determinant = b**2 - 4*a*c

solution1 = (-b-(determinant)**1/2)/(2*a)
solution2 = (-b+(determinant)**1/2)/(2*a)

print(f"The solutions are {solution1} and {solution2}\n")
