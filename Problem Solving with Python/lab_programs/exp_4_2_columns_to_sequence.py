# Develop a python program to implement the following scenario. Given a file “data.txt” with
# three columns of data separated by spaces. Read it into 3 separate simple sequences.

sequence1 = []
sequence2 = []
sequence3 = []

with open("foobar.txt") as file:
    for line in file:
        print(line.strip())
        words = line.split()
        sequence1.append(words[0])
        sequence2.append(words[1])
        sequence3.append(words[2])

print("\nSequence 1 is: ", sequence1)
print("Sequence 2 is: ", sequence2)
print("Sequence 3 is: ", sequence3)