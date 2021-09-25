/* 1. Create a trigger that can be used to keep track of all the transactions performed on the employee table. If any employee is deleted,
a new row containing the details of this employee is stored in a table called xemployee. Similarly, if a new employee is inserted, a
new row is created in another table called nemployee, and so on. If the employee table is updated, then updated rows have to be inserted
into another table called cemployee. */

CREATE TABLE EMPLOYEE12(
    EMP_SSN NUMBER PRIMARY KEY,
    EMP_LAST_NAME VARCHAR2(20),
    EMP_FIRST_NAME VARCHAR2(20),
    EMP_SALARY NUMBER,
    EMP_DATE DATE
);

CREATE TABLE XEMPLOYEE(
    EMP_SSN NUMBER,
    EMP_LAST_NAME VARCHAR2(20),
    EMP_FIRST_NAME VARCHAR2(20),
    DELDATE DATE
);

CREATE TABLE NEMPLOYEE(
    EMP_SSN NUMBER,
    EMP_LAST_NAME VARCHAR2(20),
    EMP_FIRST_NAME VARCHAR2(20),
    ADDDATE DATE
);

CREATE TABLE CEMPLOYEE(
    EMP_SSN NUMBER,
    OLDSALARY NUMBER,
    NEWSALARY NUMBER,
    UP_DATE DATE
);


CREATE OR REPLACE TRIGGER MYTRIGGER 
AFTER DELETE OR INSERT OR UPDATE ON EMPLOYEE12 
FOR EACH ROW
BEGIN        
    IF DELETING THEN   
        INSERT INTO XEMPLOYEE (EMP_SSN, EMP_LAST_NAME,EMP_FIRST_NAME, DELDATE)          
        VALUES (:OLD.EMP_SSN, :OLD.EMP_LAST_NAME,:OLD.EMP_FIRST_NAME, SYSDATE);         
    ELSIF INSERTING THEN         
        INSERT INTO NEMPLOYEE (EMP_SSN, EMP_LAST_NAME,EMP_FIRST_NAME, ADDDATE)           
        VALUES (:NEW.EMP_SSN, :NEW.EMP_LAST_NAME,:NEW.EMP_FIRST_NAME, SYSDATE);    
    ELSIF UPDATING('EMP_SALARY') THEN          
        INSERT INTO CEMPLOYEE (EMP_SSN, OLDSALARY, NEWSALARY, UP_DATE)         
        VALUES (:OLD.EMP_SSN,:OLD.EMP_SALARY, :NEW.EMP_SALARY, SYSDATE); 
    END IF;
END;
/

INSERT INTO EMPLOYEE12 VALUES(121, 'GOLDBERG', 'JOE', 37000, '11-SEP-2020');
INSERT INTO EMPLOYEE12 VALUES(122, 'CARINGTON', 'FALLON', 25000, '12-DEC-2019');
INSERT INTO EMPLOYEE12 VALUES(123, 'JENSON', 'CLAY', 12000, '08-JAN-2019');
DELETE FROM EMPLOYEE12 WHERE EMP_SSN = 121;
UPDATE EMPLOYEE12 SET EMP_SALARY = 20000 WHERE EMP_SSN = 123;

SELECT * FROM NEMPLOYEE;

/* 2. Create a trigger that limits the DML actions to the employee table to weekdays from 8.30am to 6.30pm. If a user tries to
insert/update/delete a row in the EMPLOYEE table, a warning message will be prompted. */

CREATE OR REPLACE TRIGGER MYTRIGGER_2 
BEFORE DELETE OR INSERT OR UPDATE ON EMPLOYEE12
BEGIN     
    IF (TO_CHAR(SYSDATE, 'day') IN ('sat', 'sun')) OR (TO_CHAR(SYSDATE, 'hh:mi') NOT BETWEEN '08:30' AND '18:30') THEN           
        RAISE_APPLICATION_ERROR(-20500, 'table is secured');     
    END IF;
END;
/

INSERT INTO EMPLOYEE12 VALUES(124, 'GARDNER', 'SAM',10000, '4-MAY-2020');

DELETE FROM EMPLOYEE12 WHERE EMP_SSN = 124;
DELETE FROM NEMPLOYEE WHERE EMP_SSN = 124;
DELETE FROM XEMPLOYEE WHERE EMP_SSN = 124;

/* 3. Create the following tables:
BookRec (BookName, Author, TotalCopies, AvailableCopies
MembershipRec(MemberID, Name)
BookDetails(BookID, BookName, MemberID)
CirculationRec(BookID, MemberID, IssueDate, ReturnDate)
Write a PL/SQL program to add a new book into the library. (Hint: Read Book Name, Author and total copies from the keyboard)
Autogenerate the BookID field in the BookDetails table
The entry into the BookDetails table should be done using Trigger */

CREATE TABLE BOOK_REC(
    BOOKNAME VARCHAR2(20),
    AUTHOR VARCHAR2(20),
    TOTALCOPIES NUMBER(3),
    AVAILABLECOPIES NUMBER(3)
);

CREATE TABLE MEMBERSHIPREC(
    MEMBERID VARCHAR2(20),
    NAME VARCHAR2(20)
);

CREATE TABLE BOOKDETAILS(
    BOOKID NUMBER(3),
    BOOKNAME VARCHAR2(20),
    MEMBERID VARCHAR2(20)
);

CREATE TABLE CIRCULATIONREC(
    BOOKID NUMBER(3),
    MEMBERID VARCHAR2(20),
    ISSUEDATE DATE,
    RETURNDATE DATE
);


INSERT INTO MEMBERSHIPREC VALUES('E01', 'DWIGHT SHRUTE');
INSERT INTO MEMBERSHIPREC VALUES('E02', 'ROSA DIAZ');
INSERT INTO MEMBERSHIPREC VALUES('E03', 'ERIC FOREMAN');

CREATE OR REPLACE TRIGGER MYTRIGGER_3
AFTER INSERT ON BOOK_REC
FOR EACH ROW
DECLARE
ID NUMBER(3);
CURSOR C IS SELECT * FROM BOOKDETAILS;
BEGIN
    FOR S IN C 
    LOOP 
        ID := S.BOOKID;
    END LOOP;
    IF ID IS NOT NULL THEN
        ID := ID+1;
    ELSE
        ID := 501;
    END IF;
    INSERT INTO BOOKDETAILS VALUES(ID, :NEW.BOOKNAME, 'NIL');
END;
/

DECLARE 
BOOK_NAME VARCHAR2(20);
AUTHOR_NAME VARCHAR2(20);
COPIES NUMBER(3);
ID NUMBER(3);
BEGIN
    BOOK_NAME := &BOOK_NAME;
    AUTHOR_NAME := &AUTHOR_NAME;
    COPIES := &COPIES;
    INSERT INTO BOOK_REC VALUES(BOOK_NAME,AUTHOR_NAME,COPIES,COPIES);
END;
/

/* 4. Create the following tables:
BookRec (BookName, Author, TotalCopies, AvailableCopies
MembershipRec(MemberID, Name)
BookDetails(BookID, BookName, MemberID)
CirculationRec(BookID, MemberID, IssueDate, ReturnDate)
Write a function to issue a book to a member. If book is available the function should return the return Date of the book otherwise display a message
Hint:1. Read Book name and MemberID from the keyboard
2. If sufficient copies of the book are available
a. Make necessary updations to BookRec and BookDetails table
b. Insert a new row into the CirculationRec table
c. Return date should be 30 days after the issue date */

CREATE TABLE BORROW(
    BOOKID NUMBER(3),
    BOOKNAME VARCHAR2(20),
    MEMBERID VARCHAR2(20),
    ISSUEDATE DATE,
    RETURNDATE DATE,
    AVAILABLECOPIES NUMBER(3)
);


CREATE OR REPLACE FUNCTION RETDATE(BNAME IN VARCHAR, MID IN VARCHAR)
RETURN DATE
IS
CURSOR C IS SELECT * FROM BOOK_REC;
COPY NUMBER(3);
RETURNDTE DATE;
ID NUMBER(3);
BEGIN
    COPY := -1;
    FOR S IN C 
    LOOP 
        IF(S.BOOKNAME=BNAME) THEN 
            IF(S.AVAILABLECOPIES>0) THEN 
                COPY := S.AVAILABLECOPIES;
                COPY := COPY-1;
                RETURNDTE := (SYSDATE+30);
                SELECT BOOKID INTO ID FROM BOOKDETAILS WHERE BOOKNAME=BNAME;
                DBMS_OUTPUT.PUT_LINE('BOOK IS AVAILABLE !');
                INSERT INTO BORROW VALUES(ID,BNAME,MID,SYSDATE,RETURNDTE,COPY);
            END IF;
        END IF;
    END LOOP;
    RETURN RETURNDTE;
END;
/


CREATE OR REPLACE TRIGGER MYTRIGGER_4
AFTER INSERT ON BORROW
FOR EACH ROW
BEGIN
    UPDATE BOOK_REC SET AVAILABLECOPIES=:NEW.AVAILABLECOPIES WHERE BOOKNAME=:NEW.BOOKNAME;
    INSERT INTO CIRCULATIONREC VALUES(:NEW.BOOKID, :NEW.MEMBERID, :NEW.ISSUEDATE, :NEW.RETURNDATE);
    UPDATE BOOKDETAILS SET MEMBERID = :NEW.MEMBERID WHERE BOOKNAME = :NEW.BOOKNAME;
END;
/


DECLARE 
BOOKNAME VARCHAR2(20);
RETURNDATE DATE;
MEMBERID VARCHAR2(3);
BEGIN
    MEMBERID := &MEMBERID;
    BOOKNAME := &BOOKNAME;
    RETURNDATE := RETDATE(BOOKNAME, MEMBERID);
    IF RETURNDATE IS NOT NULL THEN
    DBMS_OUTPUT.PUT_LINE('RETURN DATE : '|| RETURNDATE);
    ELSE
    DBMS_OUTPUT.PUT_LINE('THE BOOK IS NOT AVAILABLE');
    END IF;
END;
/

drop table bookdetails;
drop table mainbookrec;
drop table book_rec;

select * from bookdetails;
select * from MEMBERSHIPREC;
select * from book_rec;