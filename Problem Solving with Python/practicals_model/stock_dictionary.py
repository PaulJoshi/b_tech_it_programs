# Create a stock database using dictionaries . [Create dictionary through the program].
# The database holds records, which contain item name, number of units, and rate per unit.
# Write a program that performs the following:

#   a. Updating the stock details
#   b. Printing the stock details
#   c. Sorting the database based on the number of units

stock = []

def add_item():
    item = {}
    item["item_name"] = input("Enter name of item: ")
    item["no_of_units"] = int(input("Enter how many units: "))
    item["rate"] = float(input("Enter rate per unit: "))
    stock.append(item)

def update_item():
    name = input("Enter name of item: ")
    for i in stock:
        if i["item_name"].lower() == name.lower():
            i["no_of_units"] = int(input("Enter how many units: "))
            i["rate"] = float(input("Enter rate per unit: "))
            input("Update Complete. Press any key to continue")
            return
    print("Item not found")

def display_sorted():
    for i in sorted(stock, key=lambda x: x["no_of_units"]):
        print(f'''\nName             :   {i['item_name']}
Number of Units  :   {i['no_of_units']}
Rate             :   {i['rate']}''')

print('''
Menu:
1. Add new Item
2. Update item
3. Sort and Display
4. Exit''')
while(True):
    choice = int(input("\nEnter your choice: "))
    if choice == 1:
        add_item()
    elif choice == 2:
        update_item()
    elif choice == 3:
        display_sorted()
    else:
        exit()