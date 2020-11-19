# Program to compare two files

with open("file_1.txt") as file1 :
    with open("file_2.txt") as file2 :
        if file1.read() == file2.read() :
            print("They are the same")
        else :
            print("Not same")