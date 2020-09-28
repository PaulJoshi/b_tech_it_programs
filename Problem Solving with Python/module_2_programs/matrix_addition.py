# Write a program that defines two matrices and prints its sum

x = [[2, 5, 4],
    [1, 3, 9],
    [7, 6, 2]]

y = [[1, 8, 5],
    [1, 3, 9],
    [3, 6, 2]]

result = []
for i in range(3): 
    result.append([0] * 3)

#Addition
for i in range(len(x)):
    for j in range(len(y)):
        result[i][j] = x[i][j] + y[i][j] 

print("Resultant Matrix is: ")
for r in result: 
   print(r) 