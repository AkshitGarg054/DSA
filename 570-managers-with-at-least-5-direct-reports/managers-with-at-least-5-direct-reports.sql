# using SUBQUERY
# Step A: write a subquery to extract the IDs that appear at least 5 times in the managerId column? 
# Step B: What are the names of the employees whose id matches those IDs?

SELECT name 
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
);