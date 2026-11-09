WITH temp AS (
    SELECT emp_id, event_day, (out_time - in_time) as duration
    FROM Employees
)

SELECT event_day as day, emp_id, SUM(duration) as total_time
FROM temp
GROUP BY event_day, emp_id