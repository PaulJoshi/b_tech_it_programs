#Program to enter any character. If the character is lowercase, convert to Upper and vice versa

character = input("Enter a character: ")

if character >= 'A' and character <= 'Z': #if character.isupper()
    print("Character is UpperCase")
    character = character.lower()
    print("The lowercase character is " + character)
else :
    print("Character is LowerCase")
    character = character.upper()
    print("The uppercase character is " + character)