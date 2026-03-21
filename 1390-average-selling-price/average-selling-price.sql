SELECT p.product_id, ROUND(IFNULL(SUM(p.price * s.units) / SUM(s.units), 0), 2) as average_price
FROM Prices p LEFT JOIN UnitsSold s
ON p.product_id = s.product_id
AND s.purchase_date >= p.start_date AND s.purchase_date <= p.end_date
GROUP BY p.product_id 