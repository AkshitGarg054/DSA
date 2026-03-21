WITH temp AS (
    SELECT *,
           LAG(people, 1) OVER (ORDER BY id) AS prev1,
           LAG(people, 2) OVER (ORDER BY id) AS prev2,
           LEAD(people, 1) OVER (ORDER BY id) AS next1,
           LEAD(people, 2) OVER (ORDER BY id) AS next2
    FROM Stadium
)

SELECT id, visit_date, people
FROM temp
WHERE 
    (people >= 100 AND prev1 >= 100 AND prev2 >= 100) -- current is 3rd
    OR
    (people >= 100 AND prev1 >= 100 AND next1 >= 100) -- current is middle
    OR
    (people >= 100 AND next1 >= 100 AND next2 >= 100) -- current is 1st
ORDER BY id;