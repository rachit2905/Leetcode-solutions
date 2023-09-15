# Write your MySQL query statement below
SELECT employee_id 
FROM employees 
WHERE salary < 30000 

INTERSECT 

SELECT a.employee_id 
FROM employees a 
WHERE manager_id NOT IN (SELECT b.employee_id FROM employees b)

ORDER BY employee_id;