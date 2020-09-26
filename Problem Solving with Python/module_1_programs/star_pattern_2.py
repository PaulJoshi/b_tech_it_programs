# star_pattern_2

# Pattern 2.1
for i in range(5):
    print('*' * 5)

# Pattern 2.2
for i in range(6):
    print('*' * i)

print(['*' * i for i in range(1, 6)])

# Pattern 2.3
for i in range(1,7):
    print('\n')
    for j in range(1,i):
        print(j, end='')
