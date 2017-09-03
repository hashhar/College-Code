-- Create the database if it does not exist and use it
DROP DATABASE `Ashhar13BCS0015 - Q6`;
CREATE DATABASE IF NOT EXISTS `Ashhar13BCS0015 - Q6`;
USE `Ashhar13BCS0015 - Q6`;

-- Drop the existing tables
DROP TABLE IF EXISTS Product0015;
DROP TABLE IF EXISTS Customer0015;
DROP TABLE IF EXISTS OrderDetail0015;

-- Create Table Product
CREATE TABLE Product0015 (
	pid INT PRIMARY KEY,
	pname VARCHAR(100) NOT NULL,
	price INT NOT NULL,
	discount DECIMAL(5,2),
	pcompany VARCHAR(100) NOT NULL
);

-- Create Table Customer
CREATE TABLE Customer0015 (
	cid INT PRIMARY KEY,
	cname VARCHAR(100),
	cadd VARCHAR(500),
	ccity VARCHAR(50)
);

-- Create Table OrderDetail
CREATE TABLE OrderDetail0015 (
	oid INT NOT NULL,
	pid INT NOT NULL,
	cid INT NOT NULL,
	odate DATE NOT NULL,
	qty INT NOT NULL,
	status VARCHAR(100),
	CONSTRAINT pk_OD PRIMARY KEY (oid, pid),
	FOREIGN KEY(cid) REFERENCES Customer0015(cid) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(pid) REFERENCES Product0015(pid) ON UPDATE CASCADE ON DELETE CASCADE
);
