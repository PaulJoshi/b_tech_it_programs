declare
    TOTAL_COUNT NUMBER(30);
begin
    UPDATE TUTOR
    SET TEACHER = 'ZEN' WHERE CODE = 1;

    IF SQL%NOTFOUND THEN
        dbms_output.Put_line('NO SUBJECTS FETCHED');
    
    ELSIF SQL%FOUND THEN
        TOTAL_COUNT := SQL%ROWCOUNT;
        dbms_output.Put_line( TOTAL_COUNT || ' TEACHER NAME UPDATED ');
    END IF;
END;
/