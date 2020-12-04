# Class car with attributes model, year and price and
# a method cost() for displaying price
# Create 2 instances of the class and call the 

class Car :
    
    def __init__(self, model, year, price) :
        self.model = model
        self.year = year
        self.price = price

    def cost(self) :
        return str(self.price) + " mil"
    
car_1 = Car('Porsche', 1983, 3)
car_1 = Car('Mercedes', 1972, 7)

print(f"Price of {car_1.model} is {car_1.cost()}")