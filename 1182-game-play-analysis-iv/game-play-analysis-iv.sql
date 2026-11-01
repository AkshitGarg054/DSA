SELECT ROUND(COUNT(DISTINCT a1.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity a1 
JOIN (
    SELECT player_id, MIN(event_date) as first_date
    FROM Activity
    GROUP BY player_id
) as a2
ON a1.player_id = a2.player_id AND a1.event_date = DATE_ADD(a2.first_date, INTERVAL 1 DAY)


# a1.event_date = first_date + 1
# this addition won't work in case of: 2016-02-29 -> 2016-03-01
