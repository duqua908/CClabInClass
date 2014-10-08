##########   Section 1    #############
## loading the data from my hard drive. The path would need to be changed

housing <- read.csv("F:/MyFiles/External HD files/Academic Work/DUE-work/Thesis Semester1/R'/housing.csv", stringsAsFactors=FALSE)
View(housing)

#########    Section 2  #########

hist(housing$Market.Value.per.SqFt)

## At first look this distribution looks like a left skewed distribution
## add some more breaks to see the distribution better

hist(housing$Market.Value.per.SqFt, breaks=20)

## With the added breaks the distribution looks like a left skewed bimodal distribution the two tiered distribution probably represents a 2 different processes or environment for producing and pricing housing.



######### Section 3 Kernal Density plot ########

d<-density(housing$Market.Value.per.SqFt)
plot(d)

polygon(d, col="red", border="blue")

## Or using ggplot2 

library(ggplot2)
density<-ggplot(housing, aes(Market.Value.per.SqFt))
density + geom_density()
myGraph<-density + geom_density()

## add the Borough dimension
boroDensity<-ggplot(housing, aes(Market.Value.per.SqFt, fill=housing$Boro))+geom_density(alpha = 0.2)+xlab("Market Value per Square Foot")+ ylab("Density")+guides(fill=guide_legend(title="Borough"))+labs(title="Market Value per SqFt by Borough")

plot(boroDensity)

##This graph reveals the bimodal distribution more, The borough dimension reveals that the Manhattan distribution is significantly more expensive than the others and thus creates the second hump. 



###########   Section 4 . ########
## Start by creating a subset eliminating the unwanted values

housingSubset<-subset(housing, Total.Units <= 1000 )

## Graph the data: since there is no graph type specified I will use points because it seems to the most appropriate
## I will add a smooth curve as described in Chap 4 of Fields book. I will help make the data more legible.


GrossByMVpFS<-ggplot(housingSubset, aes(Market.Value.per.SqFt, Gross.SqFt))+geom_point()+geom_smooth()+labs(x="Market Value per SqFt", y="Gross SqFt", title="Gross SqFt by Market Value per SqFt")

plot(GrossByMVpFS)



