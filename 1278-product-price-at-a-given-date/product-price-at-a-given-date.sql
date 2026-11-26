WITH allProducts AS (
    SELECT DISTINCT product_id from Products
)

SELECT p1.product_id, COALESCE(t.new_price, 10) as price
FROM allProducts p1
LEFT JOIN (
    SELECT product_id, new_price
    FROM Products p
    WHERE change_date <= '2019-08-16'
    AND change_date = (
        SELECT MAX(p2.change_date) 
        FROM Products p2
        WHERE p2.product_id = p.product_id AND p2.change_date <= '2019-08-16' 
    )
) as t
ON p1.product_id = t.product_id 


