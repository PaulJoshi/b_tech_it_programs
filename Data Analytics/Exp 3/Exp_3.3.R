# Write a R program to create a Data Frames which contain details of 10
# employees (Name,Designation, Gender, Salary, Hire date).

x <- data.frame (
  name = c("Jacob", "Manu", "Sheba", "Diya", "Eva", "Dan", "Michelle", "Jessica", "Gary", "Eric"),
  designation = c("Assistant", "Manager", "Assistant", "CEO", "Intern", "Associate", "Associate", "Associate", "Staff", "Staff"),
  gender = c("M", "M", "F", "F", "F", "M", "M", "F", "M", "M"),
  salary = c(8, 10, 8, 24, 5, 9, 9, 9, 4, 4),
  hiredate = c("2019-05-12", "2017-02-09", "2018-05-12", "2017-02-09", "2019-05-12", "2019-01-09", "2019-05-12", "2017-09-09", "2020-05-12", "2017-04-09")
)
x$hiredate <- as.Date(x$hiredate)

x

# a) Extract 3rd and 5th rows with 1st and 3rd columns from a given data frame.

x[c(3, 5), c(1, 3)]



#b) Create a frequency table for employee with respect to gender

library('plyr')
table(x$gender)


#c) Draw a histogram for salary

hist(x$salary, xlab="petal width", ylab="sepal width", main="Width")

