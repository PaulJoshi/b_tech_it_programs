# Develop a Python program to implement the following scenario. A book shop details contains the Title of book and Number of copies of each title.
# As books are added to shop the number of copies in each should increase and as books are sold the number of copies in each should decrease.

books = {}

def change_details(choice):
    book = input(f"\nEnter name of book to {'buy' if choice == 1 else 'sell'}: ")
    count = int(input(f'How many copies of "{book}": '))
    
    if choice == 1 :
        books[book] = books.get(book, 0) + count
    else :
        if books.get(book, 0) < count :
            print("Not enough books")
            return
        books[book] = books.get(book, 0) - count

print('\n1. Add book\n2. Sell book\n3. Exit')

while(True):
    if (choice := int(input("\nEnter choice: "))) == 3 : break

    change_details(choice)

    for book, count in books.items():
        print(f" {book} : {count}")