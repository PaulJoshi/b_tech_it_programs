# Program to find sum of squares of even numbers in the range 1 to n

n = int(input("Enter a number: "))

sum = 0

for i in range(1, n):
    if i % 2 == 0:
        sum += i*i

print(sum)
