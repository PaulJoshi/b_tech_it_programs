# A book shop contains the and the number of copies for each title. Write a menu driven program that performs
# the following operation. As the books are added to the shop, the number of copies should increase and
# as the books are sold, number of copies should decrease.

books = {}
n = int(input("How many books? "))

for i in range(n):
    book = input("Enter name of book: ")
    books[book] = 1

def printbooks():
    for book, count in books.items():
        print(f" {book} : {count}")

while(True):
    print('''
        1. Add
        2. Sell
        3. Exit
        ''')
    opt = int(input("Enter option: "))
    if opt == 1 :
        book = input("Enter name of book: ")
        count = int(input("Enter number of copies: "))
        books[book] += count
        printbooks()
    elif opt == 2 :
        book = input("Enter name of book: ")
        count = int(input("Enter number of copies: "))
        books[book] -= count
        printbooks()
    else : break