#Illustrate the following with ggplot2 using mtcars data set

install.packages("ggplot2")
library("ggplot2")
data(mtcars)

#a)Make a Scatter plot of mpg vs. hp. Set color to am 

ggplot(mtcars,aes(x=mpg,y=hp))+geom_point(aes(color=factor(am)))

#b)Make a Box plot of mpg by number of gears
ggplot(mtcars,aes(x=mpg,y=factor(gear)))+geom_boxplot()

#c)Make a density plot: cyl vs wt,
#i)Facet it by am
#ii)Add a theme layer for the plot (graph title, background color etc)

ggplot(mtcars) + geom_density(aes(x=cyl),fill="dodgerblue")+
geom_density(aes(x=wt),fill="red")+
labs(title="cyl / wt DENSITY PLOT", x="cyl/wt")+facet_wrap(~ am)
