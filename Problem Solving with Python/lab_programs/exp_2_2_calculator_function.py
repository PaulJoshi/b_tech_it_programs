# 2. Implements calculator with functions like add, subtract, multiply, divide, exponent etc.

def add(a, b):
    return a + b, '+'

def subtract(a, b):
    return a - b, '-'

def multiply(a, b):
    return a * b, '×'

def divide(a, b):
    return a / b, '÷'

def exponent(a, b):
    return a ** b, '^'

print('''Operations
    1. Add
    2. Subtract
    3. Multiply
    4. Divide
    5. Exponent''')
choice = input("Enter your choice: ")

while choice in ('1', '2', '3', '4', '5'):
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    if choice == '1':
        sol = add(num1, num2)

    elif choice == '2':
        sol = subtract(num1, num2)

    elif choice == '3':
        sol = multiply(num1, num2)

    elif choice == '4':
        sol = divide(num1, num2)

    else:
        sol = exponent(num1, num2)
    
    print(f"{num1} {sol[1]} {num2} = {sol[0]}")
    break

else:
    print("Invalid Input")