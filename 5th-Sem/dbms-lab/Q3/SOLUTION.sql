-- QUES 1
SELECT *
FROM (SELECT authCity, authFirst FROM author0015) AS a
GROUP BY authCity HAVING COUNT(authCity) = 2;

-- QUES 2
SELECT b.bookid, b.copyright, b.pages, w.publisher
FROM book0015 AS b
INNER JOIN writtenby0015 AS w ON b.bookid = w.bookid
GROUP BY w.bookid HAVING COUNT(*) > 1;

-- QUES 3
DELIMITER //
CREATE PROCEDURE insertIntoAuth0015(IN authid INT, IN authFirst NVARCHAR(50), IN authMid NVARCHAR(50), IN age DATE, IN authCity NVARCHAR(50), IN authLast NVARCHAR(50))
BEGIN
	DECLARE verifyAuthid INT DEFAULT 0;
	SELECT COUNT(*) INTO verifyAuthid
	FROM author0015 AS a
	WHERE a.authid = authid;
	IF verifyAuthid = 0
	THEN
		INSERT INTO author0015 VALUES(authid, authFirst, authMid, authLast, age, authCity);
	ELSE
		SELECT 'This AuthorID already exists!';
	END IF;
END//
DELIMITER ;

-- QUES 4
DELIMITER //
CREATE PROCEDURE insertBookInfo0015(IN bookid INT, IN title NVARCHAR(100), IN copyright NVARCHAR(50), IN pages INT)
BEGIN
	DECLARE verifyBID INT DEFAULT 0;
	SELECT COUNT(*) INTO verifyBID
	FROM book0015 AS b 
	WHERE b.bookid = bookid;
	IF verifyBID = 0
	THEN
		INSERT INTO book0015 VALUES(bookid, title, copyright, pages);
	ELSE
		SELECT 'This Book ID already exists!';
	END IF;
END//
DELIMITER ;

-- QUES 5
DELIMITER //
CREATE PROCEDURE deleteAuthById0015(IN _authid INT)
BEGIN
	DECLARE verifyExists INT DEFAULT 0;
	SELECT COUNT(*) INTO verifyExists
	FROM book0015 AS b, writtenby0015 AS w
	WHERE b.bookid = w.bookid AND w.authid = _authid;
	IF verifyExists = 0
	THEN
		DELETE FROM author0015 WHERE author0015.authid = _authid;
	ELSE
		SELECT 'There are Books by the author in the Books Table, delete them first';
	END IF;
END//
DELIMITER ;

-- QUES 6
DELIMITER //
CREATE PROCEDURE deleteBookByAuthId0015(IN _authid INT)
BEGIN
	DECLARE numBooks INT DEFAULT 0;
	DECLARE _bookid INT DEFAULT 0;
	SELECT COUNT(*) INTO numBooks
	FROM book0015 AS b, writtenby0015 AS w
	WHERE b.bookid = w.bookid AND w.authid = _authid;
	IF numBooks = 0
	THEN
		SELECT 'No book by the author exists.';
	ELSE
		label1: LOOP
			IF numBooks > 0
			THEN
				SELECT bookid INTO _bookid FROM writtenby0015 WHERE writtenby0015.authid = _authid LIMIT 1;
				DELETE FROM book0015 WHERE bookid = _bookid;
				SET numBooks = numBooks - 1;
				ITERATE label1;
			ELSE
				LEAVE label1;
			END IF;
			DELETE FROM writtenby0015 WHERE writtenby0015.authid = _authid;
		END LOOP label1;
	END IF;
END//
DELIMITER ;

-- QUES 7
DELIMITER //
CREATE FUNCTION AgeValidate0015(age DATE) RETURNS NVARCHAR(100)
BEGIN
	DECLARE check_age INT;
	DECLARE message NVARCHAR(100);
	SET check_age = DATEDIFF(CURDATE(), age) / 365.25;
	IF check_age >= 18 AND check_age <= 60
	THEN
		SET message = CONCAT('Age is Valid');
	ELSE
	IF check_age < 18
	THEN
		SET message = CONCAT('Age is less than 18');
	ELSE
		SET message = CONCAT('Age is greater than 60');
		END IF;
	END IF;
RETURN message;
END//
DELIMITER ;

-- QUES 8
CREATE TABLE log0015 (
	op NVARCHAR(30) NOT NULL,
	previous NVARCHAR(100),
	after NVARCHAR(100),
	_TIMESTAMP TIMESTAMP);

DELIMITER //
CREATE trigger trig_insbook0015 AFTER INSERT ON book0015
FOR EACH ROW
BEGIN
	INSERT INTO log0015(op, AFTER, _TIMESTAMP) VALUES
	('INSERT', CONCAT(NEW.bookid, ' ', NEW.title, ' ', NEW.copyright, ' ', NEW.pages), current_timestamp());
END//
DELIMITER ;