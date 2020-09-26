# Program with for loop to calculate factorial

number = int(input("Enter a number: ")) + 1

factorial = 1
for i in range(1, number):
    factorial *= i
print(factorial)
