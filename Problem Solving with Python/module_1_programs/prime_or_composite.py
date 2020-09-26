# Program to classify the given number as prime or composite

number = int(input("Enter any number : "))
if number > 1:
    for i in range(2, number):
        if (number % i) == 0:
            print(number, "is NOT a prime number")
            break
    else:
        print(number, "is a PRIME number")
elif number == 0 or 1:
    print(number, "is a neither prime NOR composite number")
else:
    print(number, "is NOT a prime number it is a COMPOSITE number")