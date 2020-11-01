# Search an element in a list

lst = [] 

#input the list
n = int(input("Enter number of elements : "))  
for i in range(0, n): 
    ele = input("Enter an element: ")
    lst.append(ele)

#search element
flag, count = 1, 0
item = input("Enter element to search for: ")
for i in lst:
    count += 1
    if i == item:
        print(f"Element '{item}' found in list at {count}")
        flag = 0
if flag == 1: print("Element not found")