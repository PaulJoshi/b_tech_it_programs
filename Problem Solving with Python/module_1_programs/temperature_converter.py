#Program to convert temperature in fahrenheit to degrees
#Formula -> (32°F − 32) × 5/9 = 0°C

fahrenheit = float(input("Enter temperature in Fahrenheit: "))
print("Temperature in celsius is ", (fahrenheit - 32)*(5/9))