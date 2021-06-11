-- Write a pl/sql program to check whether a given 3-digit number is Armstrong or not.

declare
    n number := &n;
    s number := 0;
    r number;
    len number;
    m number;
  
begin
    m := n;
    while n > 0 loop
        r := mod(n , 10);
        s := s + power(r, 3);
        n := trunc(n / 10);
    end loop;

    if m = s
    then
        dbms_output.put_line('Armstrong');
    else
        dbms_output.put_line('Not Armstrong');
    end if;
end;
/