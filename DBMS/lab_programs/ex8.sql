
1.
declare 
n number;
r number;
fac number := 1;
begin
    n := &n;
    r := n;
    while(n>0) loop
        fac := fac*(n);
        n := n-1;
    end loop;
    dbms_output.put_line('Factorial of '||r||' = '||fac);
end;
/


2.
declare 
n number;
temp number;
r number;
s number := 0;
begin
    n := &n;
    temp := n;
    while(n>0) loop
        r := MOD(n,10);
        s := s+(r*r*r);
        n := floor(n/10);
    end loop;
    if(temp=s) then
        dbms_output.put_line('Armstrong Number');
    else 
        dbms_output.put_line('Not Armstrong Number');
    end if;
end;
/


3.
declare 
n VARCHAR2(20);
f VARCHAR2(20);
num number(3);
i number(3);
begin
    n := '&n';
    num := length(n);
    for i in reverse 1..num loop
        f := f||substr(n, i, 1);
    end loop;
    dbms_output.put_line('Reverse string is: '||f);
end;
/


4.
declare 
n number;
f number;
p number;
temp number := 0;
begin
    n := &n;
    p := n;
    while n>0 loop
        f := mod(n,10);
        temp := (temp*10)+f;
        n := trunc(n/10);
    end loop;
    if p = temp then
        dbms_output.put_line('Palindrome');
    else 
        dbms_output.put_line('Not Palindrome');
    end if;
end;
/


5.
CREATE TABLE AREA(RADIUS NUMBER, AREA NUMBER);
declare 
area number;
rad number := 5;
begin
    while(rad<16) loop
        area := 3.14*rad;
        rad := rad+1;
        INSERT INTO AREA VALUES(area, rad);
    end loop;
end;
/

6.
CREATE TABLE BANKDETAILS(
    Name VARCHAR2(25),
    ACCOUNT VARCHAR2(20),
    BALANCE VARCHAR2(20));
INSERT INTO BANKDETAILS VALUES('Paul Joshi', 1234, 1000000);
INSERT INTO BANKDETAILS VALUES('Muffin Man', 6789, 300);
DECLARE 
accno number(9);
minnum number(5) := 1000; 
xbal number(9);
name VARCHAR2(20);
BEGIN
    accno := &accno; 
    select BALANCE into xbal from BANKDETAILS 
    where ACCOUNT=accno; 
    select Name into name from BANKDETAILS 
    where ACCOUNT=accno; 
    IF(xbal < minnum) THEN
        update BANKDETAILS  
    set BALANCE=BALANCE-100 where ACCOUNT=accno;
    xbal := xbal-100; 
    dbms_output.put_line('Hello '||name||'. Rs 100 is deducted and current balance is '||xbal);
    ELSE
        dbms_output.put_line('Hello '||name||'. Your Current balance is '||xbal);
    END IF;
END;  
/


7.
DECLARE 
pre number(8);
past number(5); 
reading number(5); 
cusno number(9);
bill_amt number(9);
BEGIN
    dbms_output.put_line('====== KSEB =======');
    cusno := &cusno; 
    past := &past;
    pre := &pre;
    reading := pre-past;
    dbms_output.put_line('Consumer no : ' || cusno);
    dbms_output.put_line('Users Reading : ' || reading);
    IF(reading< 20) THEN 
        dbms_output.put_line('Bill fo the ' || Cusno || ' is = 30');
    ELSIF( reading< 100) THEN
        bill_amt := (reading*.5);
    dbms_output.put_line('Bill of the ' || Cusno || ' is = ' || bill_amt);
    ELSIF( reading< 300) THEN
        reading := reading-100;
    bill_amt := (reading*.75)+50; 
    dbms_output.put_line('Bill of the ' || Cusno || ' is = ' || bill_amt);
    ELSIF( reading< 500) THEN
        reading := reading-300;
    bill_amt := (reading*1.5)+200; 
    dbms_output.put_line('Bill of the ' || Cusno || ' is = ' || bill_amt);
    ELSE
        reading := reading-500;
    bill_amt := (reading*2.25)+500;
    dbms_output.put_line('Bill of the ' || Cusno || ' is = ' || bill_amt);
    END IF;
END; 
/