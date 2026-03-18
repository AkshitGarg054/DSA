# remember note: subquery runs first always
SELECT MAX(salary) as SecondHighestSalary from Employee where salary < (SELECT MAX(salary) from Employee);