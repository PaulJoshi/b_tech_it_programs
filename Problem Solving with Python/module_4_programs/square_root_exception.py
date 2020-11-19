# Program to find square root of a number
# If entered value is negative, handle the exception

import math

num = int(input("Enter a number: "))

if num < 0 :
    raise Exception("Negative Value not allowed!")
else :
    print(f"Square Root of {num} is {math.sqrt(num)}")