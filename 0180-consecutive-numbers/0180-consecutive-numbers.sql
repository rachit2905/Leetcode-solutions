# Write your MySQL query statement below
select distinct a_num as ConsecutiveNums
from 
(
select a.id, a.num as a_num, b.num as b_num, c.num as c_num
from Logs as a

left join Logs as b

on a.id = b.id - 1

left join Logs as c

on b.id = c.id - 1
) as d
where a_num = b_num  and a_num = c_num and b_num = c_num