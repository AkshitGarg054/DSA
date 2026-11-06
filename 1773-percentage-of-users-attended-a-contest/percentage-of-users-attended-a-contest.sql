SELECT contest_id, ROUND(COUNT(r.user_id) * 100 / (SELECT COUNT(*) FROM Users), 2) as percentage
FROM Register r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;