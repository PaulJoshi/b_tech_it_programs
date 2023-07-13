#Inverse of 

library(matlib)
data <- c(2, 3, 7, 1, 9, 3, 2, 8, 12)
A <- matrix(data, nrow = 3, ncol = 3)

print("Matrix A")
print(A)
print("Inverse of A")
inv(A)