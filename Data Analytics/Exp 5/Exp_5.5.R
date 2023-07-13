#5. Group 620 high school seniors based on their grades in three subject areas:
# English, mathematics, and science with K-means clustering method.

library(plyr)
library(ggplot2)
library(cluster)
library(lattice)
library(graphics)
library(grid)
library(gridExtra)
library(factoextra)

#import the student grades

grade_input = as.data.frame(read.csv("C:/Users/Online/Desktop/Paul Joshi/School-Students.csv"))
show(grade_input)

#formats the grades for processing. The data file contains four columns. 
#The first column holds a student identification (ID) number, and the other three columns 
#are for the grades in the three subject areas. Because the student ID is not used 
#in the clustering analysis, it is excluded from the k-means input matrix, kmdata

kmdata_orig = as.matrix(grade_input[, c("Student", "English", "Math", "Science")])
kmdata_orig
kmdata <- kmdata_orig[, 2:4]
kmdata[1:10, ]


km = kmeans(kmdata, 3, nstart=25)
km


fviz_cluster(km, data=kmdata, xlab="clusters", ylab="studentid")
