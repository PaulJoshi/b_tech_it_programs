# Program to print fibonacci series

limit = int(input("Enter limit of series: "))

a, b = 0, 1

while a < limit:
    print(a)
    a, b = b, a + b
