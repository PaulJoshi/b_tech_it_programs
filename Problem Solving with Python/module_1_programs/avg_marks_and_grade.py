#Program to enter marks of a student in 4 subject. Calculate total marks and average marks. Display grade
#avg >= 90, O
#80 < avg < 90, A+
#70 < avg < 80, A
#60 < avg < 70, B
#50 < avg < 60, C
#avg < 50, Fail

sum = 0
count = 4 #Number of students
i = 0

while i < count:
    a = int(input("Enter marks of student: "))
    sum += a
    i += 1

avg = sum / count

if avg >= 90:
    print("O")
elif avg > 80 and avg < 90:
    print("A+")
elif avg > 70 and avg < 80:
    print("A")
elif avg > 60 and avg < 70:
    print("B")
elif avg > 50 and avg < 60:
    print("C")
else: print("F")
