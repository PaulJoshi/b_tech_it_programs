# Program to find the sum of all odd terms in a group of numbers entered by the user

odd_sum = 0

while True:
    try:
        number = int(input("Enter a number (hit any char to stop): "))
        if number % 2 != 0:
            odd_sum += number
    except:
        break

print(f"The sum of odd terms is {odd_sum}")
