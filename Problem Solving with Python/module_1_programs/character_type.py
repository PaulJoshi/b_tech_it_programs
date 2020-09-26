#Program to determine type of character entered by the user
#char, digit, space

character = input("Enter a character: ")

if character.isalpha():
    print("Character is an alphabet")
elif character.isdigit():
    print("Character is a number")
elif character.isspace():
    print("Character is a space")
else:
    print("Character is a special one")

# if-elif-else statement - chained conditions/additional conditions
