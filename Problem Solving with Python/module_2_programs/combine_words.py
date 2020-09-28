# Write a program that creates a new list of words by combining words from 2 different lists

lst_1 = ["hello", "world"]
lst_2 = ["python", "programming"]
new_lst = []

for x in lst_1:
    for y in lst_2:
        new_lst.append(x + ' ' + y)

print(new_lst)

# OR
print([x + ' ' + y for x in lst_1 for y in lst_2])