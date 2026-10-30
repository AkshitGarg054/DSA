SELECT (
    SELECT DISTINCT salary 
    FROM (
        SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
        FROM Employee
    ) as t
    WHERE rnk = 2
) as SecondHighestSalary