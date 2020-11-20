# Program that contains a function is_leap_year() which takes year as arg
# and checks whether it is leap or not

def is_leap_year(year) :
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0 :
        print(f"{year} is a leap year")
    else :
        print(f"{year} is not a leap year")

year = int(input("Enter a year: "))

is_leap_year(year)