# Program that reads a file line by line
# and print four letter words in it

with open("foobar.txt") as file:

    print("4 Letter words are: ")
    
    for line in file:
        for word in line.split():
            if len(word) == 4:
                print(word)