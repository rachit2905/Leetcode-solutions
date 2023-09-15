# Write your MySQL query statement below
SELECT DISTINCT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
OR (primary_flag = 'N' AND employee_id IN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
))
GROUP BY employee_id