SET AUTOCOMMIT ON
SET SERVEROUTPUT ON

CREATE TABLE EMPLOYEE(
    EMPID NUMBER(5) PRIMARY KEY,
    EMPNAME VARCHAR2(20) NOT NULL,
    JOB VARCHAR2(10),
    MANAGER NUMBER(5),
    DEPTNO NUMBER(5),
    HIRDATE DATE,
    SAL NUMBER(7, 3)
);

DESC EMPLOYEE

CREATE TABLE DEPT( DEPTNO NUMBER(5) PRIMARY KEY,
   DEPTNAME VARCHAR2(20),
   LOCATION VARCHAR2(20));

ALTER TABLE EMPLOYEE ADD COMMISSION INTEGER;

ALTER TABLE EMPLOYEE MODIFY JOB VARCHAR2(20);

ALTER TABLE DEPT DROP COLUMN LOCATION;

ALTER TABLE EMPLOYEE RENAME COLUMN SAL TO SALARY;

DROP TABLE DEPT;

SELECT 'PAUL', 20 FROM DUAL;

SELECT SYSDATE FROM DUAL;

SELECT 15 + 10 - 5 * 2 / 5 FROM DUAL;

SELECT TABLE_NAME FROM USER_TABLES;