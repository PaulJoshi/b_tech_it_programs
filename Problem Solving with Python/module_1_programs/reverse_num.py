# Program to find the reverse of a number

number = int(input("Enter a number: "))

reverse = 0

while(number > 0): 
    digit = number % 10
    reverse = reverse * 10 + digit 
    number = number // 10
else:
    print("Cannot be reversed!")

print(f"reversed number is {reverse}")
