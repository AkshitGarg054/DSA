SELECT ( # By placing the original logic inside a SELECT (...), SQL will automatically evaluate an empty result set as null.
    SELECT DISTINCT salary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary