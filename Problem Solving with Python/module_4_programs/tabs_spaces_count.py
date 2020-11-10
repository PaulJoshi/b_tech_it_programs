# Program that accepts filename as input form the user
# Read from the file and find no. of tabs, spaces & newline characters

filename = input("Enter the filename: ")

with open(filename) as file:
    tabs, spaces, newlines = 0, 0, 0
    for char in file.read():
        if char == '\t':
            tabs += 1
        elif char == ' ':
            spaces += 1
            tabs += 1
        elif char == '\n':
            newlines += 1

print(f'''
tabs        :    {tabs}
spaces      :    {spaces}
newlines    :    {newlines}
''')