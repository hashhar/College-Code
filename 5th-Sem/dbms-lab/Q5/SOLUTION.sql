-- QUES 1
SELECT fname, minit, lname, bdate, address
FROM Employee0015
WHERE fname = 'John' AND minit = 'B.' AND lname = 'Smith'
;

-- QUES 2
SELECT E.fname, E.lname
FROM Employee0015 AS E
INNER JOIN Department0015 AS D ON E.dno = D.dnumber
WHERE D.dname = 'Administration';

-- QUES 3
SELECT E.fname, E.lname
FROM Employee0015 AS E
INNER JOIN Department0015 AS D ON E.dno = D.dnumber
INNER JOIN Works_On0015 AS W ON W.essn = E.ssn
INNER JOIN Project0015 AS P
WHERE D.dnumber = 5 AND W.hours > 10 AND P.pname = 'ProjectY';

-- QUES 4
SELECT E.fname, E.lname, S.fname AS 'Supervisor', S.lname AS 'Supervisor'
FROM Employee0015 AS E, Employee0015 AS S
WHERE E.super_ssn = S.ssn;

-- QUES 5
SELECT E.fname, E.lname
FROM Employee0015 AS E
INNER JOIN Department0015 AS D ON D.dnumber = E.dno
INNER JOIN Dept_Locations0015 AS DL ON DL.dnumber = D.dnumber
WHERE DL.dlocation = 'Houston';

-- QUES 6
SELECT E.fname, E.lname
FROM Employee0015 AS E
INNER JOIN Dependent0015 AS D ON D.essn = E.ssn
WHERE D.dependent_name LIKE "John%";

-- QUES 7
SELECT SUM(hours), COUNT(*)
FROM Employee0015 AS E
INNER JOIN Works_On0015 AS W ON W.essn = E.ssn
INNER JOIN Project0015 AS P ON W.pno = P.pnumber
GROUP BY P.pname;

-- QUES 8
SELECT AVG(E.salary)
FROM Employee0015 AS E
WHERE E.sex = 'F';

-- QUES 9: TODO
