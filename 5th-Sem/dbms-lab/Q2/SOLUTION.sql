-- QUES 1
SELECT sname
FROM student0015 AS s
INNER JOIN enrolled0015 AS e ON s.snum = e.snum
INNER JOIN class0015 AS c ON c.cname = e.cname
INNER JOIN faculty0015 AS f ON f.fid = c.fid
WHERE level = 'JR' AND fname = 'S. Jackson';

-- QUES 2
SELECT sname, age
FROM student0015 AS s
INNER JOIN enrolled0015 AS e ON s.snum = e.snum
INNER JOIN class0015 AS c ON e.cname = c.cname
INNER JOIN faculty0015 AS f ON f.fid = c.fid
WHERE e.cname = 'CSC443' AND f.fname = 'M. Shanks' ORDER BY age DESC LIMIT 1;

-- QUES 3
SELECT c.cname
FROM class0015 AS c
INNER JOIN enrolled0015 AS e ON c.cname = e.cname
WHERE (room = 'R126' OR e.cname IN (SELECT cname FROM enrolled0015 HAVING COUNT(e.cname) >= 5)) GROUP BY e.cname;

-- QUES 4
SELECT DISTINCT s.sname
FROM student0015 AS s
INNER JOIN enrolled0015 AS e ON s.snum = e.snum
INNER JOIN class0015 AS c ON c.cname = e.cname
GROUP BY c.meetsat, e.snum HAVING COUNT(e.cname) > 1;

-- QUES 5
SELECT fname
FROM faculty0015
WHERE fid IN(SELECT fid FROM class0015 GROUP BY fid HAVING COUNT(*) = (SELECT COUNT(distinct(room)) FROM class0015));

-- QUES 6
SELECT f.fname
FROM class0015 AS c 
INNER JOIN faculty0015 AS f ON f.fid = c.fid
INNER JOIN enrolled0015 AS e ON c.cname = e.cname
GROUP BY fname HAVING COUNT(*) < 5;

-- QUES 7
SELECT level, AVG(age) AS 'Average Age'
FROM student0015
GROUP BY level;

-- QUES 8
SELECT level, AVG(age) AS 'Average Age'
FROM student0015
WHERE level NOT LIKE 'JR';

-- QUES 9
SELECT f.fname, COUNT(c.cname) AS 'No. of Classes'
FROM faculty0015 AS f
INNER JOIN class0015 AS c ON c.fid = f.fid
WHERE c.room = 'BA1080' GROUP BY f.fname;

-- QUES 10
SELECT DISTINCT s.sname
FROM student0015 AS s
WHERE s.snum IN (SELECT e1.snum FROM enrolled0015 e1 GROUP BY e1.snum HAVING COUNT(*) >= ALL (SELECT COUNT(*) FROM enrolled0015 e2 GROUP BY e2.snum));