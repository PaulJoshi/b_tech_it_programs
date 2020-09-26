# Program to add two matrices

#Input first matrix
A = []
n = int(input("Enter size of matrix: "))
print("Enter the elements of first matrix: ")
for i in range(n): 
    row = []
    for j in range(n): 
        row.append(int(input()))               
    A.append(row)

print("The array is: ")
for i in range(n):
    for j in range(n):
        print(A[i][j], end=" ")              
    print()

#Input second matrix
B = []
print("Enter the elements of second matrix: ")
for i in range(n): 
    row = []
    for j in range(n): 
        row.append(int(input()))
    B.append(row)

print("The array is: ")
for i in range(n):
    for j in range(n):
        print(B[i][j], end=" ")
    print()

#Initialise result array
result = []
for i in range(n): 
    row = []
    for j in range(n): 
        row.append(n)
    result.append(row)

#Addition
for i in range(n):
    for j in range(n):
        result[i][j] = A[i][j] + B[i][j] 

print("Resultant Matrix is: ")
for r in result: 
   print(r) 