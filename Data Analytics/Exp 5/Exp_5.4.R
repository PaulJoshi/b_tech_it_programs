#4. Using decision trees, predict whether to play golf given factors 
#such as weather outlook, temperature, humidity, and wind.

library(rpart)
library(rpart.plot)
play_base <- read.table("C:/Users/Online/Desktop/Paul Joshi/Golf_Dataset.csv", header=TRUE, sep=",")
print(play_base)

fit <- rpart(Golf ~ Temperature + Outlook + Humidity + Windy, method="class", data=play_base, control=rpart.control(minsplit=1))

rpart.plot(fit, type =5 , extra=0,  uniform=TRUE, main="Decision Tree - Play?")
n<-data.frame(Outlook="sunny", Temperature="cool", Windy=FALSE, Humidity="normal")
predict(fit, newdata=n)

n<-data.frame(Outlook="sunny", Temperature="mild", Windy=FALSE, Humidity="normal")
predict(fit, newdata=n)
