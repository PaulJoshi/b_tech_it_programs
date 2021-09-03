-- 1. Write a PL/SQL block to insert the students who have passed into the table 'pass' and failed
-- into the table' fail'. Student table contains fields reg-no., mark1, mark2, mark3, name.
-- Conditions for passing: 1) Total >= 120
--                         2) mark1, mark2, mark3 >=35

CREATE TABLE STUDENTS(REG NUMBER, SNAME VARCHAR(10), MARK1 NUMBER, MARK2 NUMBER, MARK3 NUMBER);
CREATE TABLE PASS(NAME VARCHAR2(10));
CREATE TABLE FAIL(NAME VARCHAR2(10));

INSERT INTO STUDENTS(REG, SNAME, MARK1, MARK2, MARK3) VALUES(111, 'JOEL', 50, 30, 20);
INSERT INTO STUDENTS(REG, SNAME, MARK1, MARK2, MARK3) VALUES(112, 'CHRIS', 50, 50, 30);
INSERT INTO STUDENTS(REG, SNAME, MARK1, MARK2, MARK3) VALUES(113, 'DAVIS', 20, 20, 10);
SELECT * FROM STUDENTS ORDER BY REG ASC;
SELECT * FROM PASS;
SELECT * FROM FAIL;

declare
    Cursor c is select * from students;
    s c % rowtype;
    total number;
    stuname varchar(10);
begin
    open c;
    loop
    Fetch c into s;
    Exit when c%notfound;
    total := s.mark1 + s.mark2+ s.mark3;
    if(total >= 120) then
        insert into pass values(s.sname);
    else
        insert into fail values(s.sname);
    end if;
    end loop;
    close c;
end;

DROP TABLE FAIL;
DROP TABLE PASS;
DROP TABLE STUDENTS;


-- 2. A bank has an 'ACCMASTER' table where it holds the current status of a client's bank account. Another table called 'ACCTRAN' holds each transaction as it occurs at bank (ie,
-- Deposits/withdrawals of clients). The 'ACCTRAN' table must hold a flag indicating whether the transaction was credit or debit. Write SQL procedure to update the 'ACCMASTER' table
-- and sets the balance depending upon whether the account is debited or credited. The updation should be done only for those records that are not processed.

-- | ACCMASTER |  ACCTRAN                  |
-- + --------- + ------------------------- +
-- | Accno(PK) |  Accno(FK)                |
-- | Name      |  TransactionDate          |
-- | Balance   |  Deb_cred    Debit/Credit |
-- |           |  Amount                   |
-- |           |  Processed   Yes/No flag  |

CREATE TABLE ACCMASTER(ACCNO NUMBER, SNAME VARCHAR(10), BALANCE NUMBER);
CREATE TABLE ACCTRAN(ACCNO NUMBER, TRANSDATE VARCHAR2(10), DEB_CRED VARCHAR2(10), AMOUNT NUMBER, PROCESSED VARCHAR2(10));

INSERT INTO ACCMASTER(ACCNO, SNAME, BALANCE) VALUES(111, 'JOHN', 5000);
INSERT INTO ACCMASTER(ACCNO, SNAME, BALANCE) VALUES(112, 'MAC', 1000);
INSERT INTO ACCMASTER(ACCNO, SNAME, BALANCE) VALUES(113, 'MARK', 500);
INSERT INTO ACCTRAN(ACCNO, TRANSDATE, DEB_CRED, AMOUNT, PROCESSED) VALUES(111, 'JAN-2-21', 'DEBIT', 500, 'YES');
INSERT INTO ACCTRAN(ACCNO, TRANSDATE, DEB_CRED, AMOUNT, PROCESSED) VALUES(112, 'JAN-5-21', 'DEBIT', 100, 'NO');
INSERT INTO ACCTRAN(ACCNO, TRANSDATE, DEB_CRED, AMOUNT, PROCESSED) VALUES(113, 'JAN-15-21', 'CREDIT', 500, 'NO');
SELECT * FROM ACCMASTER;

declare
    Cursor c is select * from acctran;
    s c % rowtype;
begin
    open c;
    loop
    Fetch c into s;
    Exit when c%notfound;
    if s.processed = 'no' then
        if s.deb_cred = 'Debit' then
            update accmaster set balance = balance - s.amount where accno = s.accno;
    else
        update accmaster set balance = balance + s.amount where accno = s.accno;
    end if;
    end if;
    end loop;
    close c;
end;
/


-- 3. An HRD manager has decided to raise the salary of all employees in department number by
-- 0.005. Whenever any such rise is given to the employees, a record for the same is
-- maintained in the Emp_Raise table. Write a PL/SQL block to update the salary of each
-- employee and insert a record in the Emp_Raise table.
--
-- Employee Table
--
-- | Field        | Data type      | Constraints
-- + ------------ + -------------- + ------------
-- | Name         | Varchar2(6)    |
-- | EmpNo        | Number(5)      | Primary key
-- | Salary       | Number(5)      |
-- | Deptno       | Number(5)      |
--
-- Emp_Raise Table
--
-- | Field          | Data type
-- + -------------- + ------------
-- | Emp_no         | Varchar2(6)
-- | Raise_date     | Date
-- | Raise_amt      | Number

CREATE TABLE EMP(
    NAME VARCHAR2(7),
    EMPNO NUMBER(5) PRIMARY KEY,
    SALARY NUMBER,
    DEPTNO NUMBER(5)
);
DESC EMP;

INSERT INTO EMP VALUES('JOEL', 123, 12000, 1001);
INSERT INTO EMP VALUES('PAUL', 234, 20000, 1002);
INSERT INTO EMP VALUES('JOHN', 865, 30000, 1003);
INSERT INTO EMP VALUES('JANE', 237, 15000, 1004);

SELECT * FROM EMP;

CREATE TABLE EMP_RAISE(
    EMPNO NUMBER(5),
    RDATE DATE,
    RAMT NUMBER
);

DECLARE
    N NUMBER(5) := &N;
    S NUMBER;
    CURSOR C2 IS SELECT * FROM EMP WHERE N=EMP.EMPNO FOR UPDATE;
    E EMP%ROWTYPE;
BEGIN
    OPEN C2;
    FETCH C2 INTO E;
    S := E.SALARY + E.SALARY*0.005;
    UPDATE EMP
    SET SALARY = S WHERE EMPNO = N;
    DBMS_OUTPUT.PUT_LINE('EMPLOYEE DETAILS ARE STORED IN THE EMP_RAISE TABLE');
    INSERT INTO EMP_RAISE VALUES(E.EMPNO, SYSDATE, E.SALARY*0.005);
    CLOSE C2;
END;
/

SELECT * FROM EMP_RAISE;
SELECT * FROM EMP;

DROP TABLE EMP;
DROP TABLE EMP_RAISE