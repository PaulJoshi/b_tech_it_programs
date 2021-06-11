-- Write a pl/sql program to display the reverse of a string.

declare
    str VARCHAR(20) := 'beautiful';
    len num;
    str1 VARCHAR(20);
begin
    len := Length(str);
    for i in reverse 1.. len loop
        str1 := str1 || Substr(str, i, 1);
    end loop;

    dbms_output.Put_line('Reverse: ' || str1);
end;
/