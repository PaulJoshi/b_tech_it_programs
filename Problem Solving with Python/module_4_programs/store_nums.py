# Program to store n numbers into a file "input.txt"
# Read the numbers from the file
# Sort the numbers and write it to "output.txt" after deleting duplicates

import pickle
n = int(input("Enter number of elements: "))

with open("input.txt", "wb") as file1:

    for i in range(n):
        x = int(input("Enter the element: "))
        pickle.dump(x, file1)

with open("input.txt", "rb") as file2:

    list1 = []
    for i in range(n):
        list1.append(pickle.load(file2))

    print(list1)

# new_list = [i for i in sorted(list) if i not in new_list]

new_list = []
for i in sorted(list1):
    if i not in new_list:
        new_list.append(i)

with open("output.txt", "wb") as file3:
    for i in range(len(new_list)):
        pickle.dump(new_list[i], file3)