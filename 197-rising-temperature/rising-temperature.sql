# (ON w1.id = w2.id) is  not used because it joins the same row with itself, so So DATEDIFF(w1.recordDate, w2.recordDate) will always be 0
# We need to compare today’s row with yesterday’s row, so the join should be based on date difference, not id.

SELECT w1.id
FROM Weather w1 JOIN Weather w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;