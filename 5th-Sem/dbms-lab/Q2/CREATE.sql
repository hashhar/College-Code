-- Create the database if it does not exist and use it
CREATE DATABASE IF NOT EXISTS `Ashhar13BCS0015 - Q2`;
USE `Ashhar13BCS0015 - Q2`;

-- Delete existing tables
DROP TABLE IF EXISTS enrolled0015;
DROP TABLE IF EXISTS class0015;
DROP TABLE IF EXISTS student0015;
DROP TABLE IF EXISTS faculty0015;

-- Create Table Student
CREATE TABLE student0015 (
	snum INT PRIMARY KEY AUTO_INCREMENT,
	sname NVARCHAR(30) NOT NULL,
	major NVARCHAR(30) NOT NULL,
	level NVARCHAR(10) NOT NULL,
	age INT NOT NULL
);

-- Create Table Faculty
CREATE TABLE faculty0015 (
	fid INT PRIMARY KEY AUTO_INCREMENT,
	fname NVARCHAR(30) NOT NULL,
	deptid INT NOT NULL
);

-- Create Table Class
CREATE TABLE class0015 (
	cname NVARCHAR(20) PRIMARY KEY,
	meetsat NVARCHAR(10) NOT NULL,
	room NVARCHAR(10) NOT NULL,
	fid INT NOT NULL,
	FOREIGN KEY(fid) REFERENCES faculty0015(fid)
);

-- Create Table Enrolled
CREATE TABLE enrolled0015 (
	snum INT NOT NULL,
	cname NVARCHAR(20) NOT NULL,
	FOREIGN KEY(snum) REFERENCES student0015(snum),
	FOREIGN KEY(cname) REFERENCES class0015(cname)
);