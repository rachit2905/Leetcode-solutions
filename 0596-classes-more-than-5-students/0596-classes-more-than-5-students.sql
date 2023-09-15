SELECT class 
FROM
(SELECT class, COUNT(student) as cnt FROM Courses GROUP BY class) s
WHERE s.cnt>=5