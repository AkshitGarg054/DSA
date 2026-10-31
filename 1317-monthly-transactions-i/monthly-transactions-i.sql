SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') AS month, 
    country,
    COUNT(state) as trans_count, 
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount 
FROM Transactions
GROUP BY country, month

## If SELECT runs after GROUP BY then how are we able to access 'month' in the GROUP BY??
# MySQL allows you to use a SELECT alias in GROUP BY as a special exception.