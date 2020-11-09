# Program to count number of times a particular character appears in a file

item = input("Enter a char: ")

with open("foobar.txt") as file:
    buffer = file.read()
    count = 0
    for char in buffer:
        if char == item:
            count += 1

print(f"Number of '{item}' is {count}")