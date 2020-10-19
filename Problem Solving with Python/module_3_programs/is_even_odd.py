# Program using function to check if given number is even or odd

def is_even(a):
    return 0 if a % 2 == 0 else 1

num = int(input("Enter a number: "))

print("Number is even") if is_even(num) == 0 else print("Number is odd")