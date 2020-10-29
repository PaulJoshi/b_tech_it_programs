# 1. Find the value of nCr using function.

fact = lambda n: 1 if n == 1 or n == 0 else n * fact( n - 1 )

def nCr( n, r ): 
    return (fact(n) / (fact(r) * fact(n - r)))

n = int(input("Enter a number (n) : "))
r = int(input("Enter a number (r) : "))

if n >= r and r >= 0 :
    print(f"Number of Combinations (nCr) is {int(nCr(n, r))}")
else :
    print("Please enter n ≥ r ≥ 0")