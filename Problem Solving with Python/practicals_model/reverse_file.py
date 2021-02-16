# Write a program that reads text from a file and writes it into another file but in the reverse order

filename = input("Enter name of file: ")

with open(filename) as file1, open(f"{filename}_copy.txt", "w") as file2:
    for char in reversed(file1.read()):
        file2.write(char)