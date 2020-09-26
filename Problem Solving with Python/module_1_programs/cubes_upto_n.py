# Program to print the cubes of numbers upto numbers

'''
number = int(input("Enter a number: ")) + 1

print([i ** 3 for i in range(number)])

for i in range(number):
    print(i ** 3)
'''

print([i ** 3 for i in range(int(input("Enter a number: ")) + 1)])