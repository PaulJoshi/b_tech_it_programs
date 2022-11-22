
# Write an R program to find the factors of a given number using function

print_factors = function(n) {
  print(paste("The factors of", n, "are:"))
  for(i in 1:n) {
    if((n %% i) == 0) {
      print(i)
    }
  }
}

print_factors(12)
