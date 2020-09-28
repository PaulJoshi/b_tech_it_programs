# Write a program to create a list of numbers in the range 1 to 10.
# Then delete all the even numbers from the list and print the final list

num_list = []
for i in range(1, 11):
    num_list.append(i)

print(f"Original list is {num_list}")

for index, i in enumerate(num_list):
    if i % 2 == 0:
        del num_list[index]

print(f"Mod list is: {num_list}")

# OR
print(f"Mod list is: {[i for i in range(1, 11) if i % 2 != 0]}")