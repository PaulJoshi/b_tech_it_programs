
data(iris)
summary(iris)


# Histogram

hist(
	iris$Sepal.Length,
	xlab = "Sepal Length",
	ylab = "Frequency",
	main = "Width data"
)


# Boxplot

boxplot(
	Sepal.Width ~ Petal.Width,
	data = iris,
	xlab = "Petal width",
	ylab = "Sepal width",
	main = "Width data"
)


# Barplot

barplot(
	iris$Sepal.Length,
	ylab = "Sepal Length",
	main = "Sepal Length data"
)


# Scatter plot

plot(
	iris$Sepal.Length,
	xlab = "Index",
	ylab = "Sepal Length",
	main = "Sepal Length Data"
)
