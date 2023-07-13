# Implementation of Statistical functions :
# Calculate Arithmetic, Geometric, Harmonic mean, Median and Mode, First quartile(25th percentile), 56th percentile for the given data using R.
# The data about average rainfall in every month in the year of 2017. 

rainfall <- c(10, 10, 10, 10, 10, 560, 640, 520, 320, 90, 20, 10)

# MEAN
r_mean = mean(rainfall)
r_mean

# GEOMETRIC MEAN
productofr = prod(rainfall)
n = length(rainfall)
g_mean = productofr^(1/n)
g_mean

# HARMONIC MEAN
inverse_r = rainfall^(-1)
sum_r = sum(inverse_r)
h_mean = n/sum_r
h_mean

# MEDIAN
median_r <- median(rainfall)
median_r

# MODE
mode = function() {
  return(names(sort(-table(rainfall)))[1])
}
mode()

# 1st QUARTILE
r <- quantile(rainfall, 0.25)
r

# 56th PERCENTILE
res <- quantile(rainfall, 0.56)
res
