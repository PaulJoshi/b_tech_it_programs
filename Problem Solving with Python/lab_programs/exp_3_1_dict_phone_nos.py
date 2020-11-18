# Develop a python program to create dictionary of phone numbers and names of n persons.
# Display the contents of the dictionary in alphabetical order of their names

phone_dict = {}

n = int(input("How many? "))

for i in range(n):
    name = input("Enter name: ")
    number = int(input("Enter number: "))
    phone_dict[number] = name

for number, name in sorted(phone_dict.items(), key=lambda x: x[1]):
    print(f"{name} : {number}")