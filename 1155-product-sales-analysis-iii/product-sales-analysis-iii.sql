SELECT product_id, first_year, quantity, price
FROM (
    SELECT product_id, year AS first_year, quantity, price,
    DENSE_RANK() OVER (PARTITION BY product_id ORDER BY year) as rnk
    FROM Sales
) t
WHERE rnk = 1