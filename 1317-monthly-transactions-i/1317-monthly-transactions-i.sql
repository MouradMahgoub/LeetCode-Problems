# Write your MySQL query statement below


select substr(trans_date, 1, 7) as month, country,
    count(*) trans_count,
    sum(amount) trans_total_amount,
    -- count(state is 'approved') approved_count,
    sum(if(state = 'approved', 1, 0)) approved_count,
    sum(if(state = 'approved', amount, 0)) approved_total_amount

from Transactions
group by month, country






-- select  substr(trans_date, 1, 7) as month,
--         country,
--         count(id) as trans_count,
--         sum(state = 'approved') as approved_count,
--         sum(amount) as trans_total_amount,
--         sum((state = 'approved')*amount) as approved_total_amount
-- from Transactions
-- group by country, month
