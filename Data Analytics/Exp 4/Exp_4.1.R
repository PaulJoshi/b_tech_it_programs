
data(iris)
summary(iris)

#histogram
hist(iris$Sepal.Length,xlab = "Petal width",
     ylab = "Sepal width",
     main = "Width data")

#boxplot

boxplot(Sepal.Width ~ Petal.Width, data = iris,
        xlab = "Petal width",
        ylab = "Sepal width",
        main = "Width data")


#barplot

a<-iris$Sepal.Length
barplot(a,xlab = "Petal width",
        ylab = "Sepal width",
        main = "Width data")

#scatter plot

plot(a,xlab = "Petal width",
     ylab = "Sepal width",
     main = "Width data")
