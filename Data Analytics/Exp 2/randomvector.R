
# Write an R program to create a vector which contains 10 random integer values
# between -50 and +50. (Hint : sample())

v = sample(-50:50, 10, replace=TRUE)
print("Vector:")
print("10 random integer values between -50 and +50:")
print(v)
