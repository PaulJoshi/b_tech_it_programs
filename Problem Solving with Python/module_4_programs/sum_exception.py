# Program to enter two numbers and display the sum
# raise/throw an exception and handle it if a non-number value is given as input

try:
    num_1 = int(input("Enter first number: "))
    num_2 = int(input("Enter second number: "))

    print(f"Sum id {num_1 + num_2}")

except ValueError:
    print("Either or both inputs are not numbers!")