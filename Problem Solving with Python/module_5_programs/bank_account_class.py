# Program to deposit or withdraw money in a bank account

class Account :

    def __init__(self) :
        self.balance = 0
        print("New account created")

    def deposit(self) :
        amount = float(input("Enter amount to deposit: "))
        self.balance = amount

    def withdraw(self) :
        amount = float(input("Enter amount to withdraw: "))
        if amount > self.balance :
            print("Insufficient balance")
        else :
            self.balance -= amount

    def enquiry(self) :
        print(f"Account balance : {self.balance}")

acc_1 = Account()

acc_1.deposit()
acc_1.withdraw()
acc_1.enquiry()