# Program to find whether a given number is a palindrome or not

number = int(input("Enter a number: "))

check = number
reverse = 0

while(number > 0): 
    digit = number % 10
    reverse = reverse * 10 + digit 
    number = number // 10

if check == reverse:
    print("Number is a palindrome")
else:
    print("Number is not a palindrome")