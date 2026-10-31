SELECT c.name
FROM Customer c
LEFT JOIN Customer r ON c.referee_id = r.id
WHERE r.id != 2 OR r.id is NULL