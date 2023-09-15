# Write your MySQL query statement below
select MAX(salary) as SecondHighestSalary 
from Employee 
Where salary < (Select MAX(salary) as SecondHighestSalary 
from Employee  )