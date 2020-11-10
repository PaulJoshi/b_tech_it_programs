# Program that reads a file line by line
# Each line read from the file is copied to another file with line numbers specified

file_1 = open("foobar.txt")
file_2 = open("copied_foobar.txt", "w")

line_no = 1
for line in file_1:
    file_2.write(f"{line_no} {line}")
    line_no += 1

file_1.close()
file_2.close()