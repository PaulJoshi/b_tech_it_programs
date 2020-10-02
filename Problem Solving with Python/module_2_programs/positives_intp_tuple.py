# Program with list of integers. Make a new tuple that has only + numbers from the list

tup1 = (-10, 3, -4, 56, 121, -29, 3, 0, -11)
new_tup = ()

for i in tup1:
    if i > 0:
        new_tup += (i,)
print(new_tup)

# OR
print(tuple(i for i in tup1 if i > 0))


# Find index of an item
print(tup1.index(-29))
# get a sorted list from a tuple
print(sorted(new_tup))