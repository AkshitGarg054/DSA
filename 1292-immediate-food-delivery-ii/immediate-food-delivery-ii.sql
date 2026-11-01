SELECT ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) * 100 / COUNT(delivery_id), 2) as immediate_percentage
FROM (
    SELECT delivery_id, order_date, customer_pref_delivery_date,
    DENSE_RANK() OVER (PARTITION BY customer_id ORDER BY order_date) as rnk
    FROM Delivery
) t
WHERE rnk = 1