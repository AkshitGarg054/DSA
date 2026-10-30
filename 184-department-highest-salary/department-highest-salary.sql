SELECT Department, Employee, Salary
FROM (
    SELECT d.name as Department, e.name as Employee, e.salary as Salary,
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) as rnk
    FROM Employee e JOIN Department d
    ON e.departmentId = d.id
) t
WHERE rnk = 1