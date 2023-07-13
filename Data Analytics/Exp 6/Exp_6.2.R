#2. Write an R program to create a corpus of documents and preprocess them in R using stemming, 
#stop word removal, whitespace removal, convert them to lowercase and remove punctuations.

#tm, a framework for text mining applications.
#SnowballC, text stemming library.
#Wordcloud, for making wordcloud visualization.
#ggplot2, one of the best data visualization libraries.

library(SnowballC)
library(ggplot2)
library(tm)
library(wordcloud)

m = data.frame(
    c(
        "I am worried to    go to school but 34 #",
        "I worry always 345 @",
        "we should stop  worrying so   easily   "
    )
)
names(m) = "text"
m

#corpus is a collection of text or speech that has been brought together according to be a certain set of predetermined criteria".
#It arranges text in such a manner  so that preprocessing of data can be done or 
#in simple words document term matrix can be created which represent each term present in the text in one encoding in the form of a matrix .

post = Corpus(VectorSource(m$text)) # creating corpus
post  # printing corpus

# Remove punctuation

post = tm_map(post, removePunctuation)

writeLines(as.character(post[[1]]))# Inspect  document no 1
writeLines(as.character(post[[2]]))# Inspect  document no 2
writeLines(as.character(post[[3]]))# Inspect  document no 3

# Strip whitespace

post = tm_map(post, stripWhitespace)

writeLines(as.character(post[[1]]))# Inspect  document no 1
writeLines(as.character(post[[2]]))# Inspect  document no 2
writeLines(as.character(post[[3]]))# Inspect  document no 3

#convert to lowercase

post <- tm_map(post, content_transformer(tolower))

writeLines(as.character(post[[1]]))# Inspect  document no 1
writeLines(as.character(post[[2]]))# Inspect  document no 2
writeLines(as.character(post[[3]]))# Inspect  document no 3

#Stemming -  A corpus contains words that have a common root such as offering, offered and offer 
#all have a common root word so stemming enables us to replace all these words into a common root form 
#as it helps to reduce complexity and increase meaning.

post <- tm_map(post, stemDocument)
writeLines(as.character(post[[1]]))
writeLines(as.character(post[[2]]))
writeLines(as.character(post[[3]]))

#Remove stopwords - Stopwords are certain words that are present in high proportion but rarely contribute anything of sense towards serving analytical purpose. 
#These include words such as "a","the","if" etc . 

post <- tm_map(post, removeWords, stopwords("english"))

writeLines(as.character(post[[1]]))
writeLines(as.character(post[[2]]))
writeLines(as.character(post[[3]]))

