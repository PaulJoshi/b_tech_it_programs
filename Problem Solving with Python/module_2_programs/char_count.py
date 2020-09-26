# Program to count nmber of times a particular character comes in a string

string = input('Enter string: ')
char = input('Enter char: ')

count = 0
for i in string:
    if i == char:
        count += 1

print(count)