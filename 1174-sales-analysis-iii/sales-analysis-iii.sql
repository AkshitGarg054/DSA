# SELECT p.product_id, p.product_name
# FROM Product p
# JOIN Sales s ON p.product_id = s.product_id 
# WHERE s.sale_date >= '2019-01-01' AND s.sale_date <= '2019-03-31'

# The upper query will include the products which are let's say sold in feb and then again sold in october, but we don't want this.

SELECT p.product_id, p.product_name
FROM Product p
JOIN Sales s ON p.product_id = s.product_id
GROUP BY p.product_id, p.product_name # both needs to be written because we selected both in select statement
HAVING MIN(s.sale_date) >= '2019-01-01' AND MAX(s.sale_date) <= '2019-03-31'; 