# Program that reads a file and copies contents into another file
# While copying, replace all 'a's with z

filename_1 = input("Enter first filename: ")
filename_2 = input("Enter second filename: ")

with open(filename_1) as file_1, open(filename_2, "w") as file_2 :
    for char in file_1.read() :
        file_2.write('z') if char == 'a' else file_2.write(char)