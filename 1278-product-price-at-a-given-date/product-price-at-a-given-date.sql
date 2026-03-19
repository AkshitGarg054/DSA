# I went to a shop on 16/8/19, I need to return the price of all products ont that day
# basically, hme 16th date tk ke hi prices consider krne hn
# jo changes 16 ke baad hue hn vo hme nhi dekhne
# agar koi item 16th ko change nhi hui then hme uski just previous date wala change lena haii
# if koi bhi date nhi haii uske pehle, then price = 10 lena haii, coz initally was 10
# so, the question asks for finding just previous change date for every item. (if 16 date don't exist)

SELECT product_id, new_price as price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date) 
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
) # Till this point, we got the prices for items for which <= 16 date was present

UNION 

SELECT product_id, 10 
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
);
