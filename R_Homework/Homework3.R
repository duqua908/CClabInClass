## Anne Duquennois 
## Assignment 3 



################### Exercise 1 ######################

#### Section 2 ####
## Load data
housing <- read.csv("F:/MyFiles/External HD files/Academic Work/DUE-work/Thesis Semester1/R'/housing.csv", stringsAsFactors=FALSE)
View(housing)

#### Section 3 ####
## Create  a sample from this data
samp1<- sample(housing$Market.Value.per.SqFt, 50)

## I will create a density graph to compare these 2 distributions
## first convert the sample data into a data frame

samp1DataFrame<-data.frame(samp1)
library(ggplot2)
samp1Density<-ggplot(samp1DataFrame, aes(samp1)) + geom_density()
plot(samp1Density)

## do the same for the entire data set to compare the two visuals 
housingDensity<-ggplot(housing, aes(Market.Value.per.SqFt)) + geom_density()
plot(housingDensity)

## The two graphs appear to have a similar bimodal distribution but the sample graph has a much smoother distribution. 
## The verticies and the intercept values are different in the graph and the range in the sample is much smaller. 
## The sample distribution is less complex relative to the complete data set (obviously) in other words there is much less variance in the data. 

#### section 5 ####
mean(samp1)
## answer is 123.2158
samp2<- sample(housing$Market.Value.per.SqFt, 50)
samp2DataFrame<-data.frame(samp2)
samp2Density<-ggplot(samp2DataFrame, aes(samp2)) + geom_density()
plot(samp2Density)

mean(samp2)
##answer is 138.1576

mean(housing$Market.Value.per.SqFt)
## answer 131.1872

## Comparing these means we can see that they are both gravitating around the true mean. They are both 'off' by a similar amount hinting at the value of the standard error. 
## if we were to take a sample of 100 or a 1000, the larger the sample size the higher the probability that the mean of that sample be a better estimate of the mean. That said a smaller sample size could still yeild a more accurate represenation of the true mean. 
## The ideal test would be to do repeated samples of the largest sample size possible. 

#### Section 6 ####
se1<- sd(samp1)/sqrt(50)
lower<-samp1 - 1.96 * se1
upper<-samp1 + 1.96 * se1

## The assumptions for this confidence interval is that the population sample is normally distributed (or close to it). 
## You are also assuming that the sample is independently and randomly taken.
## in this case the calculated mean value of lower = 105.6644 and upper=140.7672 therefore this confidence interval does include the true value of the mean.

##### Section 7 ######
samp_mean <- rep(NA, 5000)
samp_sd <- rep(NA, 5000)
n <- 50
for (i in 1:5000) {
  samp <- sample(housing$Market.Value.per.SqFt, n) # obtain a sample of size n = 50 from the population
  samp_mean[i] <- mean(samp)    # save sample mean in ith element of samp_mean
  samp_sd[i] <- sd(samp)        # save sample sd in ith element of samp_sd
}
samp_meanDF<-data.frame(samp_mean)

samp_meanDensity<-ggplot(samp_meanDF, aes(samp_mean))+geom_density()
plot(samp_meanDensity)
mean(samp_mean)
## answer is 131.2363
## the distribution looks normally distributed around the a very close value to the true mean. 

samp_sdDF<-data.frame(samp_sd)

samp_sdDensity<-ggplot(samp_sdDF, aes(samp_sd))+geom_density()
plot(samp_sdDensity)
mean(samp_sd)
## answer is  68.29145
## the distribution looks normal

## with 50 000 sample means I would expect the distribution to be similar expcept with a shorter distribution range, ie less vairence. 
## in other words the bell curve wuld be steeper and pointyer 

#### section 8 ####

lower <- samp_mean - 1.96 * samp_sd/sqrt(n)
upper <- samp_mean + 1.96 * samp_sd/sqrt(n)
## I would expect 95% of these intervals to capture the true mean and 5% to lie outside of it.

c(lower[1], upper[1])
## answer [1] 116.9584 158.5576
## yes this interval does capture the true mean.

## Opional: That code is revealing the exact percentage of the 5000 confidence intervals that capture the true mean. 



############ Exercise 2 ###########


install.packages("arm")
library(arm)
library(foreign)

#### Section 1 ####
kidiq<- read.dta("F:/MyFiles/External HD files/Academic Work/DUE-work/Thesis Semester1/R'/Homework/kidiq.dta")
head(kidiq)

#### Section 2 ####
lmFit1kidiq<- lm(kid_score ~ 1, data=kidiq)
display(lmFit1kidiq)

##In this case the coefficient estimate is 86.80 and it would correspond to the estimated mean of the kid_score

#### Section 3 ####
lmKidiqMomHS<-lm(kid_score ~ mom_hs , data=kidiq)
display(lmKidiqMomHS)

## in this case the coef est of mom_hs(= 11.77) tells us the slope of the line for this linear regression model and the intercept (=77.55) gives us the y intercept. 
## in other words y=mx+b, kid_iq=11.77mom_hs + 77.55 (and SE) --> Since mom_hs is binary the formula basically indicate that kids whos mom goes to highschool have an average higher IQ than those who don't, 
## Kids whos mom goes to High School haven an avg IQ of 89.32 and those who don't = 77.55


lmKidiqMomiq<-lm(kid_score ~ mom_iq , data=kidiq)
display(lmKidiqMomiq)

## in this case the coef est of mom_iq(= 0.61) tells us the slope of the line for this linear regression model and the intercept (=25.80) gives us the y intercept. 
## in other words y=mx+b, kid_iq=0.61mom_iq + 25.80 (and SE) --> this means losely the higher the mom's IQ the more like the kid is to have a higer IQ 
## I would losely predict that since the slope is 0.61 and the intercept 25.8 (much larger than the slope) the Mom's IQ is not a very strong predictor for the child IQ. 

#### Section 4 ####

lmKidiqMomIQHS<-lm(kid_score ~ mom_iq + mom_hs , data=kidiq)
display(lmKidiqMomIQHS)


## Here we see wit the coefficient that both mom_iq and mom_hs are positively correlated to kid_scores. 
## In other words the higher the mom's IQ and if she went to HS the higher the prediction estimate of the kid IQ
## we also see that the coefficient of mom_hs (=5.95) is much greater than mom_iq (=0.56). 
## we can interpret this as meaning the variable mom_hs has a likely greater influence of prediction on the outcome of kid_score than mom_iq

