# Write your MySQL query statement below
with ft as (
    select s.user_id, action
    from Signups s
    left join Confirmations c
    on s.user_id = c.user_id
)
select user_id, 
    round(avg(if(action = 'confirmed', 1, 0)), 2) as confirmation_rate
from ft
group by user_id