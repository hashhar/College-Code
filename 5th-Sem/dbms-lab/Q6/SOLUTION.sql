-- QUES 2
SELECT *
FROM OrderDetail0015
WHERE status = 'success';

-- QUES 3
SELECT SUM(P.price * P.discount / 100 * O.qty) AS 'Discount given on 2015-08-28'
FROM Product0015 AS P
INNER JOIN OrderDetail0015 AS O
WHERE O.odate = '2015-08-28';

-- QUES 4
SELECT DISTINCT(P.pname)
FROM Product0015 AS P
INNER JOIN OrderDetail0015 AS O ON O.pid = P.pid
WHERE P.pname IN (SELECT pname FROM OrderDetail0015 AS o, Product0015 AS p WHERE p.pid = o.pid GROUP BY o.pid HAVING COUNT(*) > 1);

-- QUES 5
SELECT *
FROM Product0015 AS P
ORDER BY P.price DESC LIMIT 2, 1;

-- QUES 6
SELECT DISTINCT(C.cname)
FROM Customer0015 AS C
WHERE C.cid NOT IN (SELECT cid FROM OrderDetail0015);

-- QUES 7
SELECT DISTINCT(C.cname)
FROM Customer0015 AS C
INNER JOIN OrderDetail0015 AS O ON O.cid = C.cid
GROUP BY O.cid HAVING COUNT(O.cid) > 1;

-- QUES 8
SELECT DISTINCT(C.cname)
FROM Customer0015 AS C
INNER JOIN OrderDetail0015 AS O ON O.cid = C.cid
WHERE O.qty > 1 GROUP BY O.cid;

-- QUES 9
SELECT C.cname, O.qty, P.price, SUM(P.price * (1 - P.discount / 100) * O.qty) AS 'Payable Amount'
FROM OrderDetail0015 AS O
INNER JOIN Customer0015 AS C ON C.cid = O.cid
INNER JOIN Product0015 AS P ON P.pid = O.pid
GROUP BY O.cid;

-- QUES 10
SELECT C.cname, SUM(O.qty)
FROM OrderDetail0015 AS O
INNER JOIN Customer0015 AS C ON C.cid = O.cid
GROUP BY O.cid;
