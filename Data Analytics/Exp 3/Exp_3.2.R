# Create three vectors(name, age, CGPA) to store the details of 5 students and
# merge them horizontally (Hint: by columns using cbind()). 

name <- c('john', 'taylor', 'robin', 'jessica', 'eva')
age <- c(19, 21, 24, 19, 22)
CGPA <- c(7.03, 9.12, 8.0, 8.99, 7.12)

print("Merging the 3 vectors using cbind()")
cbind(name, age, CGPA)
y <- list(name, age, CGPA)
print(y)


# Create a dataframe with attributes name, age, CGPA to store the details of
# another 5 students.

x <- data.frame(
  name = c("Rick", "Dan", "Michelle", "Ryan", "Gary"),
  age= c (19, 18, 20, 22, 19),
  CGPA = c(6.3, 7.2, 9.10, 9.0, 8.25)
)
print(x)


# Merge the above data (a and b) vertically. (Hint: by rows using rbind()).
x
y
rbind(x, y)
