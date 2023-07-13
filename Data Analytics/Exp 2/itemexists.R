
# Create a list of 5 strings. Check whether an item exists in the list.
# Illustrate addition and removal of an item in the list

x <- list("Pramitha", "Peter", "Riya", "Roshin", "Paul")

if ("Riya" %in% x == TRUE) {
	print("Exists")
} else {
	print("Does not exist")
}

if ("Rahul" %in% x == TRUE) {
	print("Exists")
} else {
	print("Does not exist")
}

x <- append(x, "Sandra")
x[5] <- NULL
print(x)
