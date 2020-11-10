# Program that accepts filename as input form the user
# Read from the file and calculate percentage of vowels and consonants in file

filename = input("Enter the filename: ")

with open(filename) as file:
    vowels, consonants, count = 0, 0, 0
    for char in file.read().lower():
        if char in 'aeiou':
            vowels += 1
        elif char.isalpha():
            consonants += 1
        count += 1

print(f'''
Vowels     :    {round((vowels/count)*100, 2)} %
Consonants :    {round((consonants/count)*100, 2)} %
''')