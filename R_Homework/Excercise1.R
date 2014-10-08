## Excersise 1 

##enter all the data
 gender<-c("F","F","F","F","M","F","F","F","F","M")
 tosleep<-c(-2.5,1.5,-1.5,2,0,1,1.5,0.5,-0.5,2.5)
 wakeup<-c(5.5,8,7.5,8.5,9.,8.5,7.5,7.5,7,8.5)
##Create the data frame
 sleep.data<-data.frame(gender,tosleep,wakeup)
##name the columns
 names(sleep.data)<-c("Gender","To Sleep","Wake Up")
 View(sleep.data)
##create the hours slept colomn
 hrs.sleep<-c(wakeup-tosleep)
## add new column to the dataframe
 sleep.data$new.col<-hrs.sleep
##name the new column
 names(sleep.data)<-c("Gender","To Sleep","Wake Up","hours slept")
 View(sleep.data)
 ## Find average amount slept
 AvgSleep<-mean(hrs.sleep)
 print(AvgSleep)
## Calculate the subset using gender as a descriptor
 mean(hrs.sleep[gender=="F"])
 
 ##Excersise 2
 ##2.1
install.packages("openintro")
library("openintro")
 
 ##2.2
str(census)
summary(census)
str(census$censusYear)
summary(census$censusYear)
str(census$stateFIPScode)
 str(census$totalFamilyIncome)
 str(census$age)
 str(census$sex)
 str(census$raceGeneral)
 str(census$maritalStatus)
 str(census$totalPersonalIncome)
 summary(census$stateFIPScode)
 summary(census$totalFamilyIncome)
 summary(census$age)
 summary(census$sex)
 summary(census$raceGeneral)
 summary(census$maritalStatus)
 summary(census$totalPersonalIncome)
 
 ## now check for missing data
 
 sum(!complete.cases(census))
 ##give the overall missing values and find them in each category
 
 sum(!complete.cases(census$censusYear))
 sum(!complete.cases(census$stateFIPScode))
 sum(!complete.cases(census$totalFamilyIncome))
 sum(!complete.cases(census$age))
 sum(!complete.cases(census$sex))
 sum(!complete.cases(census$raceGeneral))
 sum(!complete.cases(census$maritalStatus))
 sum(!complete.cases(census$totalPersonalIncome))
 
 ##2.3 Make a table
 
 maritalstatus.sex<-table(census$sex,census$maritalStatus)
 print(maritalstatus.sex)
 
 ##2.4
 ##create a new factor with reordered levels
 marital.status<-factor(
   census$maritalStatus, 
   levels=c("Never married/single", 
            "Married/spouse present", 
            "Married/spouse absent",
            "Separated","Divorced", 
            "Widowed"))

 ## Make a new table with reordered factor
 maritalstatus.sex_2<-table(census$sex,marital.status)
 print(maritalstatus.sex_2)
 
## 2.5
 ## Use summary tool to show mean
summary(census$totalPersonalIncome)
 ## but since we know there are missing values skewing our results use mean () while excluding the missing values
meanPersIncome_total<-mean(census$totalPersonalIncome, na.rm=TRUE)
print(meanPersIncome_total)
 
 ## Create Subset selecting based on the observations we are looking for
 
 WM.PersIncome<-subset(census, sex=="Male" & raceGeneral=="White", select=censusYear: totalPersonalIncome)
View(WM.PersIncome)
 
 ## Calculate the Mean of the totalPers Income of this subset
 mean(WM.PersIncome$totalPersonalIncome, na.rm=TRUE)
 [1] 44991.39
 
 ## repeat stepts for black females
 BF.PersIncome<-subset(census, sex=="Female" & raceGeneral=="Black", select=censusYear: totalPersonalIncome)
View(BF.PersIncome)
 mean(BF.PersIncome$totalPersonalIncome, na.rm=TRUE)
 [1] 17311.69
 
 
 ## Excersise 3 
 
 ##3,1
 vector1<-c(35,34,38,35,37)
 
 ##3.2
 yhat<-mean(vector1)
 se<-sd(vector1)/sqrt(length(vector1))
 
 ##3.3
 ## First calculate the margin of error using t(alpha/2, df) * s/sqrt(n)
 
 me<-qt(0.025,length(vector1)-1)*se
 me
 [1] -2.040262
## add this margin of error on either sides of the sample mean
 yhat-me
 [1] 37.84026
  yhat+me
 [1] 33.75974

 ## Estimated 95% confidence level for this sample mean is (33.75974,37.84026)
 
 
 
 
 
  

