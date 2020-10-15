# Program to create a dictionary of phone numbers and names. Interacttively find out the number of entries in the dictionary

phno = {}

n = int(input("How many contacts? "))

for i in range(n):
    contactnum = int(input("Enter phone number? "))
    contactname = input("Enter name: ")
    phno[contactnum] = contactname

for number, name in phno.items():
    print(f"{number} : {name}")