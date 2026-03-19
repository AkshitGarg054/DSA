# SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
# FROM Employee e JOIN Department d
# ON e.departmentId = d.id
# GROUP BY e.departmentId 
# ORDER BY e.salary DESC;

# The above query is wrong ...GROUP BY use krne ke liye SELECTED columns must be either in GROUP BY, or inside an aggregate function.
# As, hmare selected columns totally different hn, so ye query har department ke liye randomly sirf ek row uthake print kr degi.

## WHAT if i want to print the details of all employees of all departments after grouping by departmentId??
# We can't use group by for this. Because Group by reduces rows. But here, we want all the rows ...just with some rearragement.
# So, we will need the following query --
# SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
# FROM Employee e
# JOIN Department d
# ON e.departmentId = d.id
# ORDER BY e.departmentId;


## FOLLOWING IS THE CORRECT QUERY FOR THIS QUESTION : 
# For this ques, the concept of RANK() and DENSE_RANK() will be used. (These are called WINDOW FUNCTIONS)
# These both are used to provide rank(position) to the rows of a table. (Both provide different type of ranking)
# RANK() OVER (PARTITION BY columnName ORDER BY columnName DESC) as new_col_name (This is the basic syntax)
# This RANK() or DENSE_RANK() functions will create a new column in our table which will store the rank for each row
# So, we will create this new table in a subquery and then access whatever we want, with the rank value.
# NOTE 
# Before using these rank() and dense_rank(), we must do the PARTIONING, if required.
# What is PARTIONING ?
# like is question me hme departments ke hisaab se segregate krna tha, to bss isi ko partioning bolte hn
# like kisi example me agar 3 departments hn to 3 partitions bnengi (basically partioning is nothin but grouping)


SELECT Department, Employee, Salary
FROM (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY e.salary DESC) AS rnk
    FROM Employee e JOIN Department d
    ON e.departmentId = d.id
) t
WHERE rnk <= 3;