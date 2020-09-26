# Program to find sum of numbers in a particular range

low = int(input("Enter starting number: "))
high = int(input("Enter ending number: "))

i = low
sum = 0

while i <= high :
    sum += i
    i += 1

print(f"Sum within the range is {sum}")