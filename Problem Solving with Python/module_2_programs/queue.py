# Queue

queue = []
  
queue.append('a')
queue.append('b')
queue.append('c')
  
print("Initial queue")
print(queue)
  
print("\nElements dequeued from queue")
print(queue.pop(0))
print(queue.pop(0))
  
print("\nQueue after removing elements")
print(queue)
  
print(queue.pop(0))

for i in range(1, 6):
    queue.append(int(input("Enter element to push: ")))

for i in range(1, 6):
    queue.pop(0)
