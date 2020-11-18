# Develop a python code to read a text file, copy the contents to another file after removing the blank lines.

file_1 = open("foobar.txt")
file_2 = open("copied_foobar.txt", "w")

for line in file_1:
    if line != '':
        file_2.write(line)

file_1.close()
file_2.close()