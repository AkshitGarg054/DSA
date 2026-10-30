SELECT e1.name as Employee
FROM Employee e1
WHERE salary > (
    SELECT salary
    FROM Employee e2
    WHERE e2.id = e1.managerId 
);