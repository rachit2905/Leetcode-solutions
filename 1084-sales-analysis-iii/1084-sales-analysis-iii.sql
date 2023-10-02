# Write your MySQL query statement below
Select p1.product_id,p1.product_name from Product p1 join Sales s1 on p1.product_id=s1.product_id GROUP BY p1.product_id
HAVING min(s1.sale_date) >= '2019-01-01' AND max(s1.sale_date) <= '2019-03-31'