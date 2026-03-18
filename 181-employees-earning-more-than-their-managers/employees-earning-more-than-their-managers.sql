# SELECT e.name AS Employee
# FROM Employee e JOIN Employee m
# ON e.managerId = m.managerId
# WHERE e.salary > m.salary;

## In the above query, we are comparing employees who share the same manager rather than comparing an employee to their specific manager.

## What we want : The employee's managerId must match the manager's id.

SELECT e.name AS Employee
FROM Employee e JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;