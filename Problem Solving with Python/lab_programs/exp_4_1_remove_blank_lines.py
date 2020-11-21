# Develop a python code to read a text file, copy the contents to another file after removing the blank lines.

filename = input("Enter name of file: ")

file_1 = open(filename)
file_2 = open(f"copy_{filename}", "w")

for line in file_1:
    if line != '\n':
        file_2.write(line)

file_1.close()
file_2.close()