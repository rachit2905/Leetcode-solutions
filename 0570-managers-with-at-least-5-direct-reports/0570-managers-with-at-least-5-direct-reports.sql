# Select name from (Select e.name from Employee as e Group By e.managerId Having Count(e.managerId)>=5 )
Select e.name from Employee as e Left join Employee as e1  on e.id=e1.managerId Group By e1.managerId Having Count(e1.managerId)>=5