-- Create the database IF it does not exist AND use it
CREATE DATABASE IF NOT EXISTS `Ashhar13BCS0015 - Q3`;
USE `Ashhar13BCS0015 - Q3`;

-- Delete existing tables
DROP TABLE IF EXISTS writtenby0015;
DROP TABLE IF EXISTS book0015;
DROP TABLE IF EXISTS author0015;
DROP TABLE IF EXISTS log0015;

-- Delete Procedures and Functions
DROP PROCEDURE insertIntoAuth0015;
DROP PROCEDURE insertBookInfo0015;
DROP PROCEDURE deleteAuthById0015;
DROP PROCEDURE deleteBookByAuthId0015;
DROP FUNCTION AgeValidate0015;
DROP TRIGGER trig_insbook0015;

-- Create Table Book
CREATE TABLE book0015 (
	bookid INT PRIMARY KEY AUTO_INCREMENT,
	title NVARCHAR(100),
	copyright NVARCHAR(50),
	pages INT
);

-- Create Table Faculty
CREATE TABLE author0015 (
	authid INT PRIMARY KEY AUTO_INCREMENT,
	authFirst NVARCHAR(50),
	authMid NVARCHAR(50),
	authLast NVARCHAR(50),
	age DATE,
	authCity NVARCHAR(50)
);

-- Create Table WrittenBy
CREATE TABLE writtenby0015 (
	publisher NVARCHAR(50),
	bookid INT,
	authid INT,
	FOREIGN KEY (bookid) REFERENCES book0015(bookid) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (authid) REFERENCES author0015(authid) ON DELETE CASCADE ON UPDATE CASCADE
);