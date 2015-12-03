# m1
# Midterm I Take Home Project
The goal of this project was to implement two different algorithms that calculate pi and compare their performance.

This program calculates pi using the Leibniz series until its error is less than 10^-6. It then calculates pi using the Bailey-Borwein-Plouffe series until the same error. It outputs the number of iterations needed for each alogorithm to hit that percision.

The program then calculates the time per function call of the two algorithms using the iteration times calculated in the first part. It will do this until the time is between 1 and 2 seconds. It then outputs the speed up time (ratio of the time of the two algorithms). 
