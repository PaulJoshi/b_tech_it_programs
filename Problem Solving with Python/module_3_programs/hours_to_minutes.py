# Program that takes time in hours and minutes and converts to minutes

def convert_to_minutes( hours, minutes ):
    return hours * 60 + minutes

# OR
# convert_to_minutes = lambda h, m : h * 60 + m

hours = int(input("Enter number of hours: "))
minutes = int(input("Enter number of minutes: "))

print(f"Total minutes are {convert_to_minutes( hours, minutes )}")