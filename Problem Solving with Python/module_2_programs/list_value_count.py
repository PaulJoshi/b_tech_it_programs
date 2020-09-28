# Write a program that prints multiple indices of a particular value in a list

lst = [1, 2, 3, 4, 4, 5, 4, 6, 7, 2]

m = int(input("Value to be searched: "))

print(f"{m} occurs {lst.count(m)} times at positions")

for index, i in enumerate(lst):
    if(lst[index] == m):
        print(index)