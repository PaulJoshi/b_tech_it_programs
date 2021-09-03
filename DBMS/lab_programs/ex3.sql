-- 1. Creating relationship between the databases.
--  a. Alter the client table to add Primary key constraint on CNO Column.

ALTER TABLE CLIENT ADD PRIMARY KEY (CNO);

--  b. Create foreign key constraint on Manager and Dept. No column of Employee table.

ALTER TABLE EMPLOYEE ADD FOREIGN KEY (DEPTNO) REFERENCES DEPARTMENT;

--  c. Insert a new employee with DeptNo as D006.

INSERT INTO EMPLOYEE VALUES ('E0006', 'JOSE', 'SECURITY', 'E0004', 'D004', '15-DEC-12', 500, 10000);


-- 2. Creating a database to set various constraints.
--  a. Add a constraint to make the Job column unique.

ALTER TABLE EMPLOYEE MODIFY JOB VARCHAR2(10) UNIQUE;

--  b. Add constraint to the Employee table to check if EmpId &gt; 2000.

ALTER TABLE EMPLOYEE MODIFY EMPID CHECK(EMPID > 2000);

--  c. Set Salary value by default as 25000, otherwise as the user enters.

ALTER TABLE EMPLOYEE MODIFY SALARY DEFAULT 25000;

--  d. Remove the constraint from the column Job.

ALTER TABLE EMPLOYEE DROP UNIQUE(JOB);

--  e. Display all the constraints on the Employee table.

SELECT constraint_name FROM all_constraints WHERE TABLE_NAME = 'EMPLOYEE';


INSERT INTO EMPLOYEE (EMPID, EMPNAME, JOB, MANAGER, DEPTNO, HIRDATE, COMMISSION) VALUES ('E0008', 'GARY', 'MASSEAUR', 'E0004', 'D004', '15-DEC-12', 500);