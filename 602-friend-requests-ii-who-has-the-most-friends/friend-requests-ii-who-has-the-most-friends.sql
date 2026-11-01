-- UNION ALL combines both columns into one list of friend IDs.
-- GROUP BY id counts how many times each person appears.
-- MAX(num) finds the highest friend count.

WITH AllFriends AS (
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as id FROM RequestAccepted
),
Counts AS (
    SELECT id, COUNT(*) as num
    FROM AllFriends
    GROUP BY id
)

SELECT id, num 
FROM Counts
WHERE num = (SELECT MAX(num) FROM Counts);