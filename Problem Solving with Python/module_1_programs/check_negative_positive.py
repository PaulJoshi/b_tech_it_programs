#Program to test whether number entered by a user is -, + or 0

number = int(input("Enter a number: "))

if number > 0:
    print("Number is positive")
elif number < 0:
    print("Number is negative")
elif number == 0:
    print("Number is zero")
else:
    print("Error")

