-- Write a PL/SQL code block to find factorial of a number.

declare
n number := &n;
fac number := 1;

begin
    while n > 0 loop
        fac:=n*fac;
        n:=n-1;
    end loop;
    dbms_output.put_line(fac);
end;
/