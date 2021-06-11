-- 1, anu, 20, female, 35
-- 2, devi, 20, female, 32
-- 3, anoop, 20, male, 41

-- display the name and gender of the student whose mark is above 40

declare
    cursor c1 is select * from stud where marks>40;
    r1 stud%rowtype;
begin
    open c1;
    fetch c1 into r1;
    dbms_output.put_line(r1.name);
    dbms_output.put_line(r1.gender);
    close c1;
end;
/