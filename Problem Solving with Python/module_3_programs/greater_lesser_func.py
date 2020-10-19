# Write a program using functions to comapare a and b and display which is greater

def check(x, y) :
    if x == y :
        return 0
    elif x > y :
        return 1
    else :
        return -1

a, b = 30, 10

result = check(a, b)

if result == 0:
    print("Numbers a and b are equal")
elif result == 1:
    print("a is greater than b")
else:
    print("a is less than b")