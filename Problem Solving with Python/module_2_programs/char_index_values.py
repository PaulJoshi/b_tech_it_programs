# Program to print the index values of a particular character

string = input('Enter string: ')
char = input('Enter char: ')

index = 0
for i in string:
    index += 1
    if i == char:
        print(index)
