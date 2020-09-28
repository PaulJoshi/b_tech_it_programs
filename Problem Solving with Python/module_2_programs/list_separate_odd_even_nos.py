# Write a program to create a list of numbers in a given range.
# then insert the even and odd numbers in the list to two different lsts, say,
# odd and even

num_list = []
odd = []
even = []

m = int(input("Enter starting: "))
n = int(input("Enter ending: "))

for i in range(m, n):
    num_list.append(i)
    if i % 2 == 0:
        even.append(i)
    else:
        odd.append(i)

print(f"Original list     : {num_list}")
print(f"Odd number list   : {odd}")
print(f"Even number list  : {even}")