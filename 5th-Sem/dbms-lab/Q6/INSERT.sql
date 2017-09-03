INSERT INTO Product0015 VALUES
(1, 'Pendrive', 700, 5, 'Kingston'),
(5, 'DVD', 20, 2, 'Moserbaer'),
(7, 'HeadPhone', 500, 25, 'Intex'),
(9, 'Modem', 1500, 10, 'Intex'),
(10, 'Hard Disk', 4500, 7, 'Seagate'),
(12, 'Speaker', 1000, 5, 'Creative'),
(101, 'RAM', 2000, 6, 'Hynix');

INSERT INTO Customer0015 VALUES
(1, 'Sonaal', 'Dwarka', 'New Delhi'),
(2, 'Abhinav', 'Mehrauli', 'New Delhi'),
(3, 'Abdul Rauf', 'Jamia Hostel', 'New Delhi'),
(5, 'Insaan', 'Jamia Hostel', 'New Delhi'),
(6, 'Javed Ahmed', 'Allahabad', 'Uttar Pradesh'),
(7, 'Deepak', 'Borivali', 'Mumbai'),
(8, 'Minnet Khan', 'Allahabad', 'Uttar Pradesh');

INSERT INTO OrderDetail0015 VALUES
(1, 1, 1, '2015-07-23', 2, 'success'),
(1, 7, 1, '2015-07-23', 2, 'success'),
(2, 10, 5, '2015-08-28', 5, 'success'),
(2, 12, 5, '2015-08-28', 5, 'success'),
(3, 5, 2, '2015-08-31', 20, 'success'),
(4, 9, 6, '2015-09-01', 2, 'success'),
(5, 10, 7, '2015-09-02', 1, 'success'),
(6, 12, 2, '2015-09-03', 2, 'pending'),
(7, 7, 6, '2015-08-25', 1, 'failed');

SELECT * FROM Product0015;
SELECT * FROM Customer0015;
SELECT * FROM OrderDetail0015;
