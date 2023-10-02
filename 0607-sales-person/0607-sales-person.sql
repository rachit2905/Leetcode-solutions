select s.name from 
salesperson s 
where s.sales_id not in (

select sales_id
from orders o
left join company c 
on c.com_id = o.com_id
where c.name = 'RED' )