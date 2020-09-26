#Program to find largest of 3 numbers

number1 = int(input("Enter a number: "))
number2 = int(input("Enter a number: "))
number3 = int(input("Enter a number: "))

if number1 > number2 and number1 > number3:
    print(number1, "is greatest")
elif number2 > number3:
    print(number2, "is greatest")
else:
    print(number3, "is greatest")