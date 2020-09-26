# Write a program to read a set of nos until -1 is encountered. Count number of +, - & 0s entered

positives = 0
negatives = 0
zeros = 0

while True:
    number = int(input("Enter a number: "))
    if number == -1:
        break
    elif number == 0:
        zeros += 1
    elif number > 0:
        positives += 1
    else:
        negatives += 1

print(f'''
    Number of + numbers : {positives}
    Number of - numbers : {negatives}
    Number of 0s        : {zeros}
''')
