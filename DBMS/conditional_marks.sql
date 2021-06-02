-- PL/SQL program to print the grade based on the given marks with else condition
-- (mark >= 70 Grade A, mark >=40 and mark<70 Grade B, mark >=35 and mark<40 Grade C, else 'No Grade').

DECLARE
mark NUMBER := &mark;
BEGIN
    IF( mark >= 70) THEN 
        dbms_output.put_line('Grade A'); 
    ELSE IF(mark >= 40 AND mark < 70) THEN 
        dbms_output.put_line('Grade B'); 
    ELSE IF(mark >= 35 AND mark < 40) THEN 
        dbms_output.put_line('Grade C');
    ELSE
        dbms_output.put_line('No Grade');
    END IF;
END;
/