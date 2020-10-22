# Program to calculate simple interest
# Suppose the customer is a senior citizen, ROI is 12%, for all others, ROI is 10%

def interest( p, y, s ):
    ior = 12 if s == 'y' else 10
    si = float(( p * y * ior ) / 100)
    return si 

p = float(input("Enter principal amount: "))
y = int(input("How many years? "))
s = input("Senior citizen? (y/n) ")

print(f"Interest is {interest( p, y, s, )}")