-- QUES 2
SELECT L.mach_no, S.stud_name, L.lab_no, L.description
FROM Allotment0015 AS A
INNER JOIN Student0015 AS S ON S.stud_no = A.stud_no
INNER JOIN Lab0015 AS L ON L.mach_no = A.mach_no;

-- QUES 3
SELECT doweek, COUNT(*) AS 'No. of Allotments'
FROM Allotment0015
GROUP BY doweek;

-- QUES 4
SELECT COUNT(*) AS 'No. of machines allocated to B.Tech CS'
FROM Student0015 AS S
INNER JOIN Allotment0015 AS A ON S.stud_no = A.stud_no
INNER JOIN Class0015 AS C ON S.cid = C.cid
WHERE C.cname = 'B.Tech CS';

-- QUES 5
SELECT S.stud_no, S.stud_name, S.dob, C.cid, C.cname, C.duration, L.mach_no, L.lab_no, L.description, A.doweek
FROM Student0015 AS S
INNER JOIN Allotment0015 AS A ON S.stud_no = A.stud_no
INNER JOIN Class0015 AS C ON S.cid = C.cid
INNER JOIN Lab0015 AS L ON A.mach_no = L.mach_no
WHERE S.stud_no = 5;

-- QUES 6
SELECT COUNT(*) AS 'No. of machines allocated in Lab 11 on Monday'
FROM Allotment0015 AS A
INNER JOIN Lab0015 AS L ON L.mach_no = A.mach_no
WHERE A.doweek = 'Mon' AND L.lab_no = 11;

-- QUES 7
SELECT C.cname, COUNT(*) AS 'No. of machines allocated'
FROM Class0015 AS C
INNER JOIN Student0015 AS S ON S.cid = C.cid
INNER JOIN Allotment0015 AS A ON A.stud_no = S.stud_no;

-- QUES 8
SELECT L.description, COUNT(DISTINCT A.mach_no) AS 'No. of machines allocated'
FROM Lab0015 AS L
INNER JOIN Allotment0015 AS A ON A.mach_no = L.mach_no
INNER JOIN Student0015 AS S ON S.stud_no = A.stud_no
GROUP BY L.lab_no;

-- QUES 9
SELECT S.stud_no, S.stud_name, C.cname, A.mach_no, L.lab_no
FROM Student0015 AS S
INNER JOIN Class0015 AS C ON S.cid = C.cid
INNER JOIN Allotment0015 AS A ON A.stud_no = S.stud_no
INNER JOIN Lab0015 AS L ON L.mach_no = A.mach_no
ORDER BY S.dob DESC LIMIT 1;

-- QUES 10
SELECT A.mach_no
FROM Allotment0015 AS A
INNER JOIN Student0015 AS S ON S.stud_no = A.stud_no
WHERE A.mach_no IN (SELECT a.mach_no FROM Allotment0015 AS a GROUP BY a.mach_no HAVING COUNT(a.mach_no) > 1) GROUP BY A.mach_no;