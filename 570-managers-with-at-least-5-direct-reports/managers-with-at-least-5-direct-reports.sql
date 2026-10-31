SELECT e1.name
FROM Employee e1
WHERE (
    SELECT COUNT(*)
    FROM Employee e2
    WHERE e2.managerId = e1.id
) >= 5

# How are we able to use COUNT() without using a GROUP BY??
# Because The outer query picks an employee e. The inner query counts how many employees have managerId = e.id.
# For eg: e.id = 10, then the inner query becomes:
# SELECT COUNT(*)
# FROM Employee r
# WHERE r.managerId = 10;