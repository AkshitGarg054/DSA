WITH ids AS (
    SELECT DISTINCT product_id FROM Products
),
AllProducts AS (
    SELECT product_id, 10 AS price
    FROM ids
)

SELECT p1.product_id, COALESCE(p2.price, 10) as price
FROM AllProducts p1
LEFT JOIN
(
    SELECT p.product_id, p.new_price as price
    FROM Products p
    JOIN (
        SELECT product_id, MAX(change_date) as change_date
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    ) latest
    ON p.product_id = latest.product_id AND p.change_date = latest.change_date
) p2
ON p1.product_id = p2.product_id
