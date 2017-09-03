-- Create the database if it does not exist and use it
CREATE DATABASE IF NOT EXISTS `Ashhar13BCS0015 - Q1`;
USE `Ashhar13BCS0015 - Q1`;

-- Delete existing tables
DROP TABLE IF EXISTS salary0015;
DROP TABLE IF EXISTS employee0015;
DROP TABLE IF EXISTS department0015;

-- Create Table Department
CREATE TABLE department0015 (
	deptno INT PRIMARY KEY AUTO_INCREMENT,
	dname NVARCHAR(20),
	manager NVARCHAR(20),
	loc NVARCHAR(20)
);

-- Create Table Employee
CREATE TABLE employee0015 (
	empno INT PRIMARY KEY AUTO_INCREMENT,
	name NVARCHAR(20) NOT NULL,
	deptno INT NOT NULL,
	job NVARCHAR(50) NOT NULL,
	hiredate DATE,
	sal INT,
	commission INT,
	dob DATE,
	city NVARCHAR(20) NOT NULL,
	phone INT,
	FOREIGN KEY(deptno) REFERENCES department0015(deptno)
	ON UPDATE CASCADE ON DELETE CASCADE
);

-- Create Table Salary
CREATE TABLE salary0015 (
	eno INT,
	basic INT,
	HR INT,
	DA INT,
	tax INT,
	FOREIGN KEY(eno) REFERENCES employee0015(empno)
	ON UPDATE CASCADE ON DELETE CASCADE
);