SELECT e.name
FROM Employee as e
JOIN Employee as e1
WHERE e.id = e1.managerId
GROUP BY e1.managerId
HAVING count(e1.id) >= 5;