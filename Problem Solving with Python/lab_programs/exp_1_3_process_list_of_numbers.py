#Input a list of n numbers. Calculate and display the average of numbers. Also display the
#square of each value in the list

lst = [] 

#input the list
n = int(input("Enter number of elements : "))  
for i in range(0, n): 
    ele = int(input())
    lst.append(ele)

print(f"\nAverage of entered numbers is {sum(lst) / len(lst)}")
print(f"The square of each value in the list is {[i*i for i in lst]}\n")