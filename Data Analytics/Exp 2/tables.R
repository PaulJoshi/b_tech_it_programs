
# Write an R program to create an array with three columns,three rows and
# two "tables", taking two vectors as input to the array.

v1 = c(1, 3, 5, 7)
v2 = c(2, 4, 6, 8, 10)
arra1 = array(c(v1, v2),dim = c(3,3,2))
print(arra1)
