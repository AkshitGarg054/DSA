## Extract total_end_time and total_start_time in separate tables, join them and then extract the actual thing required

SELECT s.machine_id, ROUND((e.end_time - s.start_time) / e.total_processes, 3) AS processing_time
FROM (
    SELECT machine_id, SUM(timestamp) as end_time, COUNT(process_id) AS total_processes
    FROM Activity
    WHERE activity_type = 'end'
    GROUP BY machine_id
) e
JOIN (
    SELECT machine_id, SUM(timestamp) as start_time
    FROM Activity
    WHERE activity_type = 'start'
    GROUP BY machine_id
) s
ON s.machine_id = e.machine_id;


