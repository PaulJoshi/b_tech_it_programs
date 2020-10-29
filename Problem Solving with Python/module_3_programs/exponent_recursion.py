# Calculate the exponent of a number using recursion

def exponent( x, y ):
    if y == 0 :
        return 1
    else :
        return (x * exponent(x, y - 1))

# OR using lambda
exp = lambda x, y : 1 if y == 0 else x * exp(x, y - 1)

n = int(input("Enter number: "))
power = int(input("Enter power: "))

print(f"Result is {exponent(n, power)}")
print(f"Result using lambda is {exp(n, power)}")