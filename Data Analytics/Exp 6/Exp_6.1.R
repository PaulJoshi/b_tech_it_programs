#1. Write an R program to perform sentiment analysis using the review dataset.

library(syuzhet)

#Using stringsAsFactors=FALSE. By default, when building or importing a data frame, 
#the columns that contain characters (i.e., text) are coerced (=converted)
#into the factor data type. 

df1 <- read.csv("C:/Users/Online/Desktop/Paul Joshi/AmazonReview.csv", stringsAsFactors=FALSE)
review1 <- as.character(df1$Content)

#obtain sentiment scores

get_nrc_sentiment('happy')
get_nrc_sentiment('abuse')

#store dataset into new variable

s1 <- get_nrc_sentiment(review1)

#Combine text and sentiment columns

review_sentiment <- cbind(df1$Content, s1)

#Barplot for sentiments

barplot(colSums(s1) ,col=rainbow(10) ,ylab='Count', main='Amazon Feedback')

