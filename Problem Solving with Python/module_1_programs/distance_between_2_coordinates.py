#Program to find distance between 2 coordinates

x1 = float(input("Enter x coordinate of first point: "))
y1 = float(input("Enter y coordinate of first point: "))

x2 = float(input("Enter x coordinate of second point: "))
y2 = float(input("Enter y coordinate of second point: "))

print("Distance is: ", ((x1 - x2)**2 + (y1 - y2)**2)*0.5)