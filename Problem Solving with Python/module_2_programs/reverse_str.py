# Program to reverse a string

string = input('Enter string: ')

print(string[::-1])

new_string = ''
i = len(string) - 1
while i >= 0:
    new_string += string[i]
    i -= 1

print(new_string)