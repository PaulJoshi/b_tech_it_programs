# Program that accepts 2 positive numbers m and n where m <= n
# Return numbers between 1 and n that are divisible by m

def divisible(m, n) :
    nums = []
    for i in range(n) :
        if i % m == 0 :
            nums.append(i)
    return nums

m = int(input("Enter m: "))
n = int(input("Enter n: "))

print(f"Numbers are {divisible(m, n)}")