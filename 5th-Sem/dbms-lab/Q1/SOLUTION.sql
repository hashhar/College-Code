-- QUES 1
SELECT name, city
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE d.dname = 'AC';

-- QUES 2
SELECT name, dname
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE e.sal > 10000;

-- QUES 3
-- Part 1
SELECT name
FROM employee0015
ORDER BY name ASC;
-- Part 2
SELECT name
FROM employee0015
ORDER BY name DESC;

-- QUES 4
UPDATE employee0015
SET city = 'Delhi'
WHERE empno = 2;

-- QUES 5
SELECT SUM(sal) AS 'Total Salary'
FROM employee0015 AS e
WHERE e.city = 'Delhi';

-- QUES 6
SELECT empno, name, deptno, job, hiredate, dob, city, phone,
basic, HR, DA, tax
FROM employee0015 AS e
INNER JOIN salary0015 AS s ON e.empno = s.eno
ORDER BY s.tax DESC LIMIT 1;

-- QUES 7
SELECT *
FROM employee0015
ORDER BY hiredate DESC LIMIT 1;

-- QUES 8
SELECT *
FROM employee0015
ORDER BY sal DESC LIMIT 1, 1;

-- QUES 9
SELECT *
FROM employee0015 AS e
WHERE 2 = (SELECT COUNT(DISTINCT sal) FROM employee0015 WHERE e.sal <= sal);

-- TODO: QUES 10 (Second highest using MINUS)

-- QUES 11
SELECT *
FROM employee0015
ORDER BY sal DESC LIMIT 6, 1;

-- QUES 12
SELECT COUNT(*) AS 'Total Clerks'
FROM employee0015
WHERE job = 'Clerk';

-- QUES 13
SELECT dname, COUNT(*) AS 'Total Clerks'
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE e.job = 'Clerk' GROUP BY d.deptno HAVING COUNT(*) = 1;

-- QUES 14
SELECT d.dname, e.deptno, COUNT(name) AS 'Total Clerks'
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE e.job = 'Clerk' GROUP BY e.deptno ORDER BY name DESC LIMIT 0, 1;

-- QUES 15
SELECT d.dname, COUNT(*) AS 'Total Employees'
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
GROUP BY d.deptno;

-- QUES 16
SELECT job, MIN(sal) AS 'Lowsest Salary'
FROM employee0015
GROUP BY job ORDER BY sal DESC;

-- QUES 17
SELECT deptno, AVG(sal) AS 'Lowest Average Salary'
FROM employee0015
GROUP BY deptno ORDER BY AVG(sal) ASC LIMIT 1;

-- QUES 18
SELECT job, MIN(sal) AS 'Lowest Salary', MAX(sal) AS 'Highest Salary', AVG(sal) AS 'Average Salary'
FROM employee0015
GROUP BY job;

-- QUES 19
SELECT MAX(sal) - MIN(sal) AS 'Difference between Maximum and Minimum Salaries'
FROM employee0015;

-- QUES 20
SELECT name AS 'Names starting with Aay'
FROM employee0015
WHERE name LIKE 'Aay%';

-- QUES 21
SELECT name AS 'Hired between 2009 and 2011'
FROM employee0015
WHERE hiredate BETWEEN '2009-04-02' AND '2011-09-08';

-- QUES 22
SELECT job
FROM employee0015
GROUP BY job;

-- QUES 23
SELECT SUM(sal) AS 'Total salaries earned by department 3'
FROM employee0015
WHERE deptno = 3;

-- QUES 24
SELECT e.name, e.deptno, d.dname
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE e.job = 'Clerk';

-- QUES 25
SELECT e.name, d.manager
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno;

-- QUES 26
SELECT e.name
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE d.loc = 'Delhi';

-- QUES 27
SELECT e.name, d.dname
FROM employee0015 AS e
INNER JOIN department0015 AS d ON e.deptno = d.deptno
WHERE e.job = 'Manager';

-- QUES 28
SELECT name
FROM employee0015
WHERE deptno = 1 AND sal >= ANY(SELECT sal FROM employee0015 WHERE deptno = 3);

-- QUES 29
SELECT deptno, dname AS 'Empty Department'
FROM department0015
WHERE deptno NOT IN(SELECT deptno FROM employee0015);

-- QUES 30
ALTER TABLE employee0015
DROP FOREIGN KEY employee0015_ibfk_1;

ALTER TABLE salary0015 DROP
FOREIGN KEY salary0015_ibfk_1;

DELETE FROM employee0015
WHERE deptno = 2;

DELETE FROM department0015
WHERE deptno = 2;