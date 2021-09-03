-- 1. Practice of SQL TCL commands like Rollback, Commit and Savepoint
-- a. Delete all clients whose Baldue is 0 or below.

DELETE FROM CLIENT WHERE BALDUE=0;

SELECT * FROM CLIENT;

SAVEPOINT SAVE;

-- b. Write a query to undo the above delete query.

ROLLBACK;

SELECT * FROM CLIENT;

-- 2. Practice of SQL DCL commands for granting and revoking user privileges.
-- a) Write a query to grant all privileges of client table to nearby user, whose ID is U1903068.

GRANT ALL ON CLIENT TO U1903068;

-- b) Write a query to grant some privileges of Employee table to nearby user.

GRANT SELECT ON EMPLOYEE TO U1903068;

-- c) Write a query to revoke all privileges of client table from the user.

REVOKE ALL ON CLIENT FROM U1903068;

-- d) Write a query to revoke some privileges of employees table from the user.

REVOKE SELECT ON EMPLOYEE FROM U1903068;