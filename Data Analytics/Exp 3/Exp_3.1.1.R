# R program for matrix multiplication

m <- matrix(1:8, nrow=4 , ncol=2)
print("Matrix m : ")
m

n <- matrix(11:18, nrow=2 , ncol=4)
print("Matrix n : ")
n

print("Multiplied Matrix : ")
m %*% n
