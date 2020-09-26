# stack

stack = [] 

stack.append('a') 
stack.append('b') 
stack.append('c') 
  
print('Initial stack') 
print(stack) 

print('\nElements poped from stack:') 
print(stack.pop())
  
print('\nStack after elements are poped:') 
print(stack) 
  
for i in range(1, 6):
    stack.append(int(input("Enter element to push: ")))

for i in range(1, 6):
    stack.pop()

