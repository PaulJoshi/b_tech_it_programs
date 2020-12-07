# Class that stores a string and all its status such as
# number of uppercase/lowercase characters, vowels, consonants, spaces
# and display status of the entered string

class StringStatus :
    
    def __init__(self) :

        self.str = input("\nEnter a string: ")
        self.uppercase = len([i for i in self.str if i.isupper()])
        self.lowercase = len([i for i in self.str if i.islower()])
        self.vowels = len([i for i in self.str if i in 'aeiou'])
        self.consonants = len([i for i in self.str if i not in 'aeiou .,/?'])
        self.spaces = len([i for i in self.str if i == ' '])

    def print_status(self) :

        for attr, value in self.__dict__.items():
            print(f"{attr} : {value}")


str_1 = StringStatus()
str_1.print_status()