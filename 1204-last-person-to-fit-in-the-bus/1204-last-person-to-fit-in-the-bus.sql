SELECT t1.person_name 
FROM (SELECT q.person_name, SUM(q.weight) OVER (ORDER BY q.turn) sum FROM Queue q) t1
WHERE t1.sum <= 1000
ORDER BY t1.sum DESC 
LIMIT 1