with data as (
  select 
      d.name Department, 
      e.name Employee, 
      e.Salary,
      DENSE_RANK() over(partition by d.name order by e.salary desc) rnk
  from Employee e
  INNER JOIN Department d
  ON e.departmentid = d.id
)
Select Department, Employee, Salary
FROM data 
where rnk <4