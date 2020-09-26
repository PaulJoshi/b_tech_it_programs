# Program to print all numbers from m to n and classify them as even or odd

m = int(input("Enter starting number: "))
n = int(input("Enter ending number: ")) + 1

#for i in range(m, n):
#    print(f"{i} is {'even' if i % 2 == 0 else 'odd'}")

print([f"{i} is {'even' if i % 2 == 0 else 'odd'}" for i in range(m, n)])
