INSERT INTO student0015 VALUES
(101, 'Helen', 'CS', 'JR', 19),
(102, 'Charles', 'CS', 'SR', 21),
(103, 'Andy', 'CS', 'GR', 25),
(104, 'Bob', 'CS', 'SR', 23),
(105, 'Zorba', 'CS', 'GR', 31);

INSERT INTO faculty0015 VALUES
(201, 'S. Jackson', 301),
(202, 'M. Shanks', 301),
(203, 'I. Teach', 302);

INSERT INTO class0015 VALUES
('CSC343', 'W1', 'BA1080', 201),
('CSC443', 'T2', 'BA1170', 202),
('ECE300', 'M1', 'BA1080', 203),
('ECE201', 'F12', 'BA1060', 203),
('CSC165', 'R3', 'BA1170', 202),
('ECE301', 'T2', 'BA1080', 201);

INSERT INTO enrolled0015 VALUES
(101, 'CSC343'),
(101, 'CSC443'),
(101, 'ECE300'),
(102, 'CSC343'),
(102, 'ECE201'),
(103, 'CSC343'),
(103, 'CSC443'),
(103, 'ECE300'),
(103, 'ECE201'),
(105, 'CSC343'),
(103, 'ECE301');

SELECT * FROM student0015;
SELECT * FROM faculty0015;
SELECT * FROM class0015;
SELECT * FROM enrolled0015;