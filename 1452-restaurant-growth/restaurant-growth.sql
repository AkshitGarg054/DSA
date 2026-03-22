-- SELECT *
-- FROM Customer c1 JOIN Customer c2
-- ON DATEDIFF(c2.visited_on, c1.visited_on) = 6
-- GROUP BY c1.visited_on 

SELECT c2.visited_on, 

    (SELECT SUM(amount) 
    FROM Customer
    WHERE visited_on BETWEEN c1.visited_on AND c2.visited_on) as amount,

    ROUND((SELECT SUM(amount) / 7
    FROM Customer
    WHERE visited_on BETWEEN c1.visited_on AND c2.visited_on), 2) as average_amount

FROM Customer c1 JOIN Customer c2
ON DATEDIFF(c2.visited_on, c1.visited_on) = 6
GROUP BY c1.visited_on 


