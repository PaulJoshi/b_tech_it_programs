# Function that accepts 3 integers and returns True if any of
# the integers is zero, else, returns False

def check_zero(*args) :
    for arg in args :
        if arg == 0 :
            return 1
    return 0

a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
c = int(input("Enter a number: "))

print(bool(check_zero(a, b, c)))