# Program to split the line in a file into a series of words

with open("foobar.txt") as file:

    words = []

    for line in file.read().split():
        words.append(line)

print(words)

