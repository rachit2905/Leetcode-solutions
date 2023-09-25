# Write your MySQL query statement below
Select e.email as Email from Person e join Person p on e.email=p.email and e.id!=p.id group by e.email;