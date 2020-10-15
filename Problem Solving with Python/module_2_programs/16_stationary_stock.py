# Create a dictionary named stock. Interactively enter the following elements into the stock
# pencil: 400, pen: 1000, erasor: 200, ink: 50

stock = {}

n = int(input("How many items? "))

for i in range(n):
    product = input("Enter product? ")
    count = int(input("Enter count: "))
    stock[product] = count

for product, count in stock.items():
    print(f" {product} : {count}")

# Traverse inside the dictionary and delete the product ink

stock = {"Pencil": 400, "Pen": 1000, "Erasor": 200, "Ink": 50}

for key in stock.keys():
    if key == "Ink": del stock[key]
# OR del stock['Ink']

for product, count in stock.items():
    print(f" {product} : {count}")