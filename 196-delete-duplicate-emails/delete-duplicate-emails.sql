DELETE p2 # DELETE p2.id nhi ayega
FROM Person p1 JOIN Person p2
ON p1.email = p2.email AND p1.id < p2.id 