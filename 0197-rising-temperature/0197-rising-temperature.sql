select w1.id from Weather w1 cross join Weather w2 where w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY) and w1.temperature > w2.temperature;
