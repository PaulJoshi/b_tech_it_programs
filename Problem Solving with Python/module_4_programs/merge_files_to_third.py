# Program to merge two files into a third one

filename_1 = input("Enter first filename: ")
filename_2 = input("Enter second filename: ")
filename_3 = input("Enter output filename: ")

with open(filename_1) as file1 :
    with open(filename_2) as file2 :
        with open(filename_3, "w") as file3 :
            buffer = file1.read() + file2.read()
            file3.write(buffer)