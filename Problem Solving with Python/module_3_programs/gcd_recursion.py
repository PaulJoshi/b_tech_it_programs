# Find the greatest common divisor of two numbers
# (Largest integer that divides both the numbers)

def gcd( a, b ):
    if a % b == 0:
        return b
    else:
        return gcd( b, a % b )

# OR
gcd = lambda a, b : b if a % b == 0 else gcd( b, a % b )


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
print(f"Greatest common divisor of {a} and {b} is {gcd(a,b)}")