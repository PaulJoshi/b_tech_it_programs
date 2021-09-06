-- 1. Create an Employee table with attributes - empid, ename, salary, dept, edate. Write a procedure to
-- accept two arguments: empid and sal_incr (the amount by which to increase the employee’s salary), to 
-- update salary with increase if employee exists, record the effective date and display the current basic.

CREATE TABLE EMPLOYEE_PROC (
    EMPID NUMBER(5) PRIMARY KEY,
    ENAME VARCHAR2(20) NOT NULL,
    SALARY NUMBER(7),
    DEPT NUMBER(5),
    EDATE DATE
);

INSERT INTO EMPLOYEE_PROC(EMPID, ENAME, SALARY, DEPT) VALUES(121, 'DAVE', 20000, 10);
INSERT INTO EMPLOYEE_PROC(EMPID, ENAME, SALARY, DEPT) VALUES(122, 'ALEX', 30000, 12);
INSERT INTO EMPLOYEE_PROC(EMPID, ENAME, SALARY, DEPT) VALUES(123, 'JOHN', 40000, 13);
INSERT INTO EMPLOYEE_PROC(EMPID, ENAME, SALARY, DEPT) VALUES(124, 'MARY', 50000, 10);

CREATE OR REPLACE PROCEDURE SALARYUPDATE(EMP_ID IN EMPLOYEE_PROC.EMPID%TYPE, SAL_INCR IN EMPLOYEE_PROC.SALARY%TYPE) AS 
CURSOR C IS SELECT * FROM EMPLOYEE_PROC;
SAL NUMBER(7);
FLAG NUMBER(1) := 0;
BEGIN 
    FOR S IN C
    LOOP	
        IF S.EMPID = EMP_ID THEN
            SAL := SAL_INCR + S.SALARY;	
            FLAG := 1;
            DBMS_OUTPUT.PUT_LINE('DATA FOUND!');
            DBMS_OUTPUT.PUT_LINE('UPDATE SALARY = '||SAL);
            UPDATE EMPLOYEE_PROC SET SALARY=SAL,EDATE = SYSDATE WHERE EMPLOYEE_PROC.EMPID = EMP_ID;
        END IF;
    END LOOP;
    IF FLAG = 0 THEN 
        DBMS_OUTPUT.PUT_LINE('NO DATA FOUND FOR EMP_ID:' || EMP_ID);
    END IF;
END;
/


-- 2. Create a procedure which increases the Commission of the given employee of the Employee
-- table by 5%.
-- 
-- | EMPID      | EMPNAME    | JOB             | MANAGER       | DEPTNO       | HIREDATE      | SALARY     | COMMISION
-- + ---------- + ---------- + --------------- + ------------- + ------------ + ------------- + ---------- + ---------
-- | E0001      | ABEY       | TESTER          | E0004         | D004         | 15-DEC-12     | 30000      | 525
-- | E0002      | JESTO      | ANALYST         | E0001         | D002         | 24-MAR-11     | 25000      | 683
-- | E0003      | ADARSH     | SENIOR CLERK    | E0004         | D004         | 10-JAN-13     | 15000      | 525
-- | E0005      | BONY       | MANAGER         | E0002         | D001         | 11-APR-11     | 50000      | 1050
-- | E0006      | MANU       | SUPPLIER        | E0001         | D003         | 19-JUN-13     | 50000      | 473

UPDATE EMPLOYEE SET COMMISSION = 525 WHERE EMPID = 'E0001';
UPDATE EMPLOYEE SET COMMISSION = 683 WHERE EMPID = 'E0002';
UPDATE EMPLOYEE SET COMMISSION = 525 WHERE EMPID = 'E0003';
UPDATE EMPLOYEE SET COMMISSION = 1050 WHERE EMPID = 'E0005';
UPDATE EMPLOYEE SET COMMISSION = 473 WHERE EMPID = 'E0006';

CREATE OR REPLACE PROCEDURE COMMISIONUPDATE(EMP_ID IN EMPLOYEE.EMPID%TYPE) AS
NAME VARCHAR2(20);
BEGIN
	SELECT EMPNAME INTO NAME FROM EMPLOYEE WHERE EMPLOYEE.EMPID = EMP_ID;
	UPDATE EMPLOYEE SET COMMISSION = COMMISSION + COMMISSION * 0.05 WHERE EMPLOYEE.EMPID = EMP_ID;
	DBMS_OUTPUT.PUT_LINE('COMMISSION FOR EMPID: ' || EMP_ID || ' UPDATED!');
EXCEPTION 
WHEN NO_DATA_FOUND
THEN 
	DBMS_OUTPUT.PUT_LINE('NO DATA FOUND FOR EMPID: ' || EMP_ID);
END;
/


-- 3. Write SQL procedure for a banking application which accepts the account number and amount
-- withdraw. If the balance after withdrawal is less than 1000, give an error message using user
-- defined exception. Else update the table with new balance.

CREATE TABLE BANK(
	ACCNO NUMBER(3),
	NAME VARCHAR2(10),
	BAL NUMBER(5)
);

INSERT INTO BANK VALUES(101, 'ARUN', 1200);
INSERT INTO BANK VALUES(102, 'VARUN', 1000);
INSERT INTO BANK VALUES(103, 'TARUN', 820);

CREATE OR REPLACE PROCEDURE BALANCEUPDATE(NO IN BANK.ACCNO%TYPE, AMNT IN BANK.BAL%TYPE) AS
BALANCE NUMBER(5);
INSUFFICIENT_BALANCE EXCEPTION;
BEGIN
	SELECT BAL INTO BALANCE FROM BANK WHERE BANK.ACCNO = NO;
	IF BALANCE < 1000 THEN 
		RAISE INSUFFICIENT_BALANCE;
	ELSE
		BALANCE := BALANCE - AMNT;
		UPDATE BANK SET BAL = BALANCE WHERE ACCNO = NO;
		DBMS_OUTPUT.PUT_LINE('BALANCE SUCCESSFULLY WITHDRAWAL FOR ACCOUNT NUMBER: ' || NO);
	END IF;
EXCEPTION
WHEN INSUFFICIENT_BALANCE
THEN 
	DBMS_OUTPUT.PUT_LINE('ACCOUNT NUMNBER: ' || NO || ' DOES NOT HAVE SUFFICIENT BALANCE!');
WHEN NO_DATA_FOUND
THEN 
	DBMS_OUTPUT.PUT_LINE('DATA FOR ACCOUNT NUMBER: ' || NO ||' IS NOT FOUND!');
END;
/


-- 4. Write a PL/SQL procedure that takes three numbers as parameters and displays the LCM and GCD
-- of the three numbers.

CREATE OR REPLACE PROCEDURE GCD(A IN NUMBER, B IN NUMBER, C IN NUMBER) AS
SMALLER NUMBER;
RESULT NUMBER;
BEGIN
RESULT := 1;
IF A <= B AND A <= C THEN 
	SMALLER := A;
ELSIF B <= A AND B <= C THEN
	SMALLER := B;
ELSE
	SMALLER := C;
END IF;
FOR I IN 1..SMALLER 
LOOP
	IF(MOD(A, I) = 0 AND MOD(B, I) = 0 AND MOD(C, I) = 0) THEN
		RESULT := I;
	END IF;
END LOOP;
DBMS_OUTPUT.PUT_LINE('GCD OF ' || A || ' , ' || B || ' AND ' || C || ' = ' || RESULT);
END;
/

CREATE OR REPLACE PROCEDURE LCM(A IN NUMBER, B IN NUMBER, C IN NUMBER) AS
MULTI NUMBER;
LCM_VALUE NUMBER;
FLAG NUMBER;
BEGIN
LCM_VALUE := 1;
MULTI := A*B*C;
FOR I IN 1..MULTI-1
LOOP
	IF LCM_VALUE = 1  THEN
		IF(MOD(MULTI,I) = 0)THEN
			IF(MOD(I,B) = 0 AND MOD(I,A) = 0 AND MOD(I,C) = 0) THEN 
				LCM_VALUE := I;
			END IF;
		END IF;
	END IF;
END LOOP;
IF MOD(A,B) = 0 AND MOD(A,C) = 0 THEN 
	LCM_VALUE := A;
ELSIF MOD(B,A) = 0 AND MOD(B,C) = 0 THEN 
	LCM_VALUE := B;
ELSIF MOD(C,A) = 0 AND MOD(C,B) = 0 THEN
	LCM_VALUE := C;
ELSIF LCM_VALUE = 1 THEN 
	LCM_VALUE := MULTI;
END IF;
DBMS_OUTPUT.PUT_LINE('LCM OF ' || A || ' , ' || B || ' AND ' || C || ' = ' || LCM_VALUE);
END;
/

DECLARE
X NUMBER;
Y NUMBER;
Z NUMBER;
BEGIN
X := &X;
Y := &Y;
Z := &Z;
LCM(X, Y, Z);
GCD(X, Y, Z);
END;
/


-- 5. Create table Student(RegNo, name, marks).
--      a) Write a procedure to display average mark of the students from the Student table.
--      b) Write a procedure to display mark of a student with the given student register number.

CREATE TABLE STUDENT10(
	REGNO NUMBER,
	NAME VARCHAR2(20),
	MARKS NUMBER
);

INSERT INTO STUDENT10 VALUES(501, 'STEVE', 89);
INSERT INTO STUDENT10 VALUES(502, 'ERICA', 78);
INSERT INTO STUDENT10 VALUES(503, 'ELLE', 90);
INSERT INTO STUDENT10 VALUES(504, 'DUSTIN', 52);
INSERT INTO STUDENT10 VALUES(505, 'BILLY', 65);

CREATE OR REPLACE PROCEDURE AVERAGEMARKS(NO IN STUDENT10.REGNO%TYPE) AS
CURSOR C IS SELECT * FROM STUDENT10;
AVGVAL NUMBER;
BEGIN
AVGVAL := 0;
FOR S IN C
LOOP
	AVGVAL := AVGVAL + S.MARKS;
END LOOP;
DBMS_OUTPUT.PUT_LINE('1)...TOTAL MARKS = ' || AVGVAL);
AVGVAL := AVGVAL/5;
DBMS_OUTPUT.PUT_LINE('.....AVERAGEMARKS = ' || AVGVAL);
END;
/

CREATE OR REPLACE PROCEDURE DISPLAYMARKS(NO IN STUDENT10.REGNO%TYPE) AS
STUDENTMARK VARCHAR2(20);
BEGIN
	SELECT MARKS INTO STUDENTMARK FROM STUDENT10 WHERE STUDENT10.REGNO=NO;
	DBMS_OUTPUT.PUT_LINE('2)...STUDENTS MARK OF STUDENT WITH REGNO:' || NO || ' = ' || STUDENTMARK);
	EXCEPTION
	WHEN NO_DATA_FOUND 
	THEN 
	DBMS_OUTPUT.PUT_LINE('2)...NO RECORD OF STUDENT WITH REGNO:' || NO || ' FOUND!');
END;
/

DECLARE
REGNO NUMBER;
BEGIN
REGNO := &REGNO;
AVERAGEMARKS(REGNO);
DISPLAYMARKS(REGNO);
END;
/