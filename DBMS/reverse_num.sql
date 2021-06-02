declare
n number;
r number;
begin
    n := &n;
    r := 0;
    while (n>0)
        loop
            r := (r*10) + mod(n, 10);
            n := floor(n/10);
        end loop;
    dbms_output.put_line('Reverse of the number is: ' || r);
end;
/