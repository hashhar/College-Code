INSERT INTO department0015 VALUES
(1, 'IT', 'Ashhar', 'Delhi'),
(2, 'CIVIL', 'Anas', 'Mumbai'),
(3, 'ELEC', 'Amit', 'Delhi'),
(4, 'HR', 'Aamir', 'Kanpur'),
(5, 'AC', 'Aayush', 'Kanpur'),
(6, 'Dummy', 'Random', 'Chicago');

INSERT INTO employee0015 VALUES
(1, 'Ashhar', 1, 'Design', '2013-01-01', 100000, 10000, '1995-09-07', 'Delhi', NULL),
(2, 'Anas', 2, 'Structure', '2013-09-07', 50000, 5000, '1995-08-08', 'Mumbai', NULL),
(3, 'Amit', 3, 'Drives', '2013-07-13', 80000, 8000, '1995-07-24', 'Delhi', NULL),
(4, 'Aamir', 4, 'Clerk', '2012-06-17', 60000, 6000, '1994-09-29', 'Kanpur', NULL),
(5, 'Aayush', 5, 'Clerk', '2013-02-18', 60000, 6000, '1995-07-14', 'Kanpur', NULL),
(6, 'Basit', 2, 'Manager', '2013-01-11', 38000, 3800, '1995-07-12', 'Delhi', NULL),
(7, 'Sonaal', 1, 'Dev', '2013-01-01', 30000, 3000, '1995-05-06', 'Delhi', NULL),
(8, 'Gaurav', 4, 'Manager', '2013-09-07', 18000, 1800, '1995-04-09', 'Delhi', NULL),
(9, 'Random', 2, 'Clerk', '2010-01-01', 20000, 1000, '1990-05-06', 'Chicago', NULL);

INSERT INTO salary0015 VALUES
(1, 100000, 1000, 2000, 3000),
(2, 50000, 8000, 2000, 4000),
(3, 80000, 1000, 1000, 1000),
(4, 60000, 5000, 8000, 9000),
(5, 60000, 3000, 5000, 5000),
(6, 38000, 800, 600, 1000),
(7, 30000, 200, 800, 600),
(8, 18000, 500, 400, 190);

SELECT * FROM department0015;
SELECT * FROM employee0015;
SELECT * FROM salary0015;