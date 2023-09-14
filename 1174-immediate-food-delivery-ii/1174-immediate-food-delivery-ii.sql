# Write your MySQL query statement below
SELECT ROUND(AVG(a.immediate_percentage) * 100, 2) as immediate_percentage FROM (SELECT 
  IF(MIN(order_date) = MIN(customer_pref_delivery_date), 1, 0) as immediate_percentage
FROM delivery GROUP BY customer_id ORDER BY customer_id, order_date) a;