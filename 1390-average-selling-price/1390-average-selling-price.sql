# Write your MySQL query statement below
select product_id, IFNULL(ROUND(SUM(units*price)/SUM(units), 2), 0) average_price from
    (select P.product_id, price, units
    from Prices P
    left join UnitsSold U
    on P.product_id = U.product_id and purchase_date Between start_date and end_date) TT
group by product_id;