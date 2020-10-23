# Find sum of series 1/1! + 4/2! + 27/3!

f, s = 1, 0.0

def factorial(n):
    if (n == 0 or n == 1): 
        return 1
    return [f * i for i in range(1, n + 1)]

n = int(input("Enter the value of n: "))
for i in range(1, n + 1):
    s += s / factorial(s)

print(s)