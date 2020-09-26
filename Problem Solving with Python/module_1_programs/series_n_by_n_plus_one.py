# Program to print sum of series 1/2 + 2/3 + 3/4 + ....upto n/n + 1

n = int(input("Enter a number: ")) + 1

sum = 0
for i in range(n):
    sum += n/n + 1

print(f"Sum is {sum}")