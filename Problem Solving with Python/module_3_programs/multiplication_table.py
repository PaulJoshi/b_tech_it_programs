# Program to display multiplication table for n * n size for any given n

def display_table(n): 
    for i in range (n + 1):
        print(f"{n} × {i} = {n * i}")
  
n = int(input("Enter a number: "))
display_table(n)