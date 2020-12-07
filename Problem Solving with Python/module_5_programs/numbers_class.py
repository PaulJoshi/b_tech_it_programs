# Program that has a class Numbers with values stored in a list. Write method called maximum() which
# finds the largest value in the list (max() not allowed)

class Numbers :

    def __init__(self):
        self.numbers = []
    
    def enter_values(self) :
        print("Enter numbers: (-1 to stop)")
        while(True) :
            num = int(input())
            if num == -1 :
                break
            else :
                self.numbers.append(num)
    
    def maximum(self) :
        max = self.numbers[0]
        for i in self.numbers :
            if i > max :
                max = i
        return max

num_list = Numbers()
num_list.enter_values()
print(f"Max is {num_list.maximum()}")