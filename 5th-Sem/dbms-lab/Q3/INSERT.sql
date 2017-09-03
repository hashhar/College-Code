INSERT INTO book0015 VALUES
(1, 'Book 1', 'Copyright 1', 100),
(2, 'Book 2', 'Copyright 2', 120),
(3, 'Book 3', 'Copyright 3', 130),
(4, 'Book 4', 'Copyright 4', 140),
(5, 'Book 5', 'Copyright 1', 150),
(6, 'Book 6', 'Copyright 2', 160),
(7, 'Book 7', 'Copyright 3', 170),
(8, 'Book 8', 'Copyright 4', 180),
(9, 'Book 9', 'Copyright 5', 190),
(10, 'Book 10', 'Copyright 1', 200);

INSERT INTO author0015 VALUES
(1, 'Alan Wake', NULL, NULL, '1995-11-07', 'New York'),
(2, 'Dan Brown', NULL, NULL, '1993-11-07', 'New York'),
(3, 'Jeffrey Archer', NULL, NULL, '1991-11-07', 'Chicago'),
(4, 'Premchand', NULL, NULL, '1985-11-07', 'Patna'),
(5, 'Gulzar', NULL, NULL, '1975-11-07', 'Delhi');

INSERT INTO writtenby0015 VALUES
('Publisher 1', 1, 1),
('Publisher 1', 2, 1),
('Publisher 1', 3, 1),
('Publisher 2', 4, 2),
('Publisher 3', 5, 2),
('Publisher 4', 6, 3),
('Publisher 4', 7, 3),
('Publisher 4', 8, 4),
('Publisher 1', 9, 5),
('Publisher 1', 10, 5),
('Publisher 1', 10, 1),
('Publisher 1', 10, 3);

SELECT * FROM book0015;
SELECT * FROM author0015;
SELECT * FROM writtenby0015;