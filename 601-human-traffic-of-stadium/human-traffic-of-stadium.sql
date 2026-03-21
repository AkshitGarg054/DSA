## Whenever consecutive rows ki baat ho, then think of ROW_NUMBER and then take diff with it
## consecutive rows have constant difference

SELECT id, visit_date, people
FROM (
    SELECT *, id - ROW_NUMBER() OVER (ORDER BY id ASC) as diff
    FROM Stadium
    WHERE people >= 100
) t1
WHERE diff in (
    SELECT diff
    FROM (
        SELECT id - ROW_NUMBER() OVER (ORDER BY id ASC) as diff
        FROM Stadium
        WHERE people >= 100
    ) t2                    
    GROUP BY diff 
    HAVING COUNT(diff) >= 3 
)
