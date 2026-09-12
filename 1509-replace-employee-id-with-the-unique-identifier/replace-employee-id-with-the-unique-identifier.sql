SELECT eu.unique_id, e.name
FROM EmployeeUNI eu RIGHT JOIN Employees e
ON e.id = eu.id 