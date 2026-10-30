-- SELECT *, DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) as rnk
-- FROM Employee
-- WHERE rnk <= 3 

-- The upper query is wrong because sql cannot identify rnk column because IN SQL, WHERE is evaluated before SELECT.
-- Order of execution: FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> WINDOW FUNCTION -> ORDER BY

SELECT Department, Employee, Salary
FROM (
    SELECT d.name as Department, 
    e.name as Employee, 
    e.salary as Salary, 
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) as rnk
    FROM Employee e JOIN Department d ON e.departmentId = d.id
) t
WHERE rnk <= 3


