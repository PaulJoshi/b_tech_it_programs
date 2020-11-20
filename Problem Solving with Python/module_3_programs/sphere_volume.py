# Program using a function that computes area and volume of a sphere

import math

def sphere(r) :
    area = 4 * math.pi * (r ** 2)
    volume = (4 / 3) * math.pi * (r ** 3)
    return area, volume

radius = int(input("Enter radius of sphere: "))

area, volume = sphere(radius)
print(f"Volume is {volume} and Area is {area} for sphere of Radius {radius}")