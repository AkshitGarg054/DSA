# using JOIN
# The "Self-Join" Concept: In this table, managers are also employees. To get the name of the manager who has 5 reports, you have to look at the table twice: once to count the reports and once to find the name associated with that managerId.
# Step A: Who are the IDs that appear at least 5 times in the managerId column? 
# Step B: What are the names of the employees whose id matches those IDs?

SELECT e1.name
FROM Employee e1 JOIN Employee e2
ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerId) >= 5;