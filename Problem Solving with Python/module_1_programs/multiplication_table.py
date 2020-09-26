# Program to print multiplication table of a number entered by a user

number = int(input("Enter a number: "))

for i in range(number):
    print(f"{number} x {i} = {number * i}")