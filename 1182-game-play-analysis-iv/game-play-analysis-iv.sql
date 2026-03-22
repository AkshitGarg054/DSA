WITH first_login AS (
    SELECT player_id, MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
), 
required AS (
    SELECT DISTINCT a1.player_id as player_id
    FROM Activity a1 JOIN first_login f
    ON a1.player_id = f.player_id AND 
    DATEDIFF(a1.event_date, f.first_date) = 1
)

SELECT ROUND(COUNT(player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
FROM required;
