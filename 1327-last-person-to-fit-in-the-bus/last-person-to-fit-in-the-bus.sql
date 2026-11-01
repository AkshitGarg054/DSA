SELECT person_name
FROM (
    SELECT *, SUM(weight) OVER (ORDER BY turn) as running_sum
    FROM Queue
    ORDER BY turn
) t
WHERE running_sum <= 1000
ORDER BY running_sum DESC
LIMIT 1