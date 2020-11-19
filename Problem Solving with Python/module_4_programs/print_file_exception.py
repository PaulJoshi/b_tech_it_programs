# Program that reads text from a file and prints only those lines
# that has the word print

filename = input("Enter name of file: ")

try :
    with open(filename) as file :
        for line in file.read().split('\n') :
            if line.find('print') != -1 :
                print(line.replace('print', ''))    # removes 'print' from the line
except :
    print(f"{filename} : No such file found!")