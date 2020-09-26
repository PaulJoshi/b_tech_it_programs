# Program to calculate sum of digits of a number

number = int(input("Enter a number: "))

sum = 0

while number > 0:
    digit = int(number % 10)
    sum += digit
    number /= 10

print(f"Sum of digits is {sum}")