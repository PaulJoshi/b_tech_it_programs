# 3. Find factorial of a given number using recursion.

factorial = lambda n: 1 if n == 1 or n == 0 else n * factorial( n - 1 )

n = int(input("Enter any number: "))

if n >= 0:
    print(f"The factorial of {n} is {factorial(n)}")
else:
    print("Please enter a positive integer")