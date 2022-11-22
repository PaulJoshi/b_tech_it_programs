
# Write an R program to create a 3*3*3-dimensional array of 27 elements. 

v =  sample(1:5, 27, replace = TRUE)
dim(v) = c(3, 3, 3)
print("3-dimension array: ")
print(v)
