# The UNION ALL CTE syntax needs SELECT before each category.

WITH c AS (
    SELECT 'Low Salary' as category
    UNION ALL 
    SELECT 'Average Salary' as category
    UNION ALL 
    SELECT 'High Salary' as category
)

SELECT c.category as category, COALESCE(COUNT(t.account_id), 0) as accounts_count
FROM c 
LEFT JOIN (
    SELECT account_id, 
    CASE 
        WHEN income < 20000 THEN 'Low Salary' 
        WHEN income > 50000 THEN 'High Salary'
        ELSE 'Average Salary'
    END AS salary_range
    FROM Accounts
) t 
ON c.category = t.salary_range
GROUP BY c.category