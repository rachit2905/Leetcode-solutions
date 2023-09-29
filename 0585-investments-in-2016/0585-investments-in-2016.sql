# Write your MySQL query statement below
select round(sum(t.tiv_2016), 2) as tiv_2016
from (
    select
        p1.tiv_2016, 
        (select sum(if(p2.tiv_2015 = p1.tiv_2015 and p1.pid != p2.pid, 1, 0)) from insurance p2) > 0 as is_same_tiv_2015,
        (select sum(if(p3.lat = p1.lat and p3.lon = p1.lon and p1.pid != p3.pid, 1, 0)) from insurance p3) = 0 as is_unique_geo
    from insurance p1
) t
where t.is_same_tiv_2015 = 1 and t.is_unique_geo = 1