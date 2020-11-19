# Program which handles the error or exception occuring when a file is being opened

filename = input("Enter file name: ")

try :
    with open(filename) as file:
        print(file.read())

except IOError :
    print(f"{filename} : No such file found!")