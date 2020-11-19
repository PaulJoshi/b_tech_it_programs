# Program to read a file that contains small case characters
# Write these characters into another file with all lowercase characters
# converted to uppercase

filename_1 = input("Enter first filename: ")
filename_2 = input("Enter second filename: ")

with open(filename_1) as file1, open(filename_2, "w") as file2 :
    buffer = file1.read().upper()
    file2.write(buffer)