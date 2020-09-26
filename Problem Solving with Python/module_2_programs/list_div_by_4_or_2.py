# Program that creates a list of nums form 1 - 20 that are either divisible by 2 or by 4

lst = []
for i in range(1, 20):
    if i % 2 == 0 or i % 4 == 0 :
        lst.append(i)

print(lst)

#OR
print(list(i for i in range(1, 20) if i % 2 == 0 or i % 4 == 0))