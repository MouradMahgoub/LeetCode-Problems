select query_name, round(avg(rating/position), 2) quality, round(100*avg(rating < 3), 2) poor_query_percentage 
from Queries
group by query_name











-- # Write your MySQL query statement below
-- select
--     query_name,
--     round(avg(rating / position), 2) as quality,
--     round(sum(rating < 3)*100/count(rating), 2) as poor_query_percentage
-- from Queries
-- where query_name is not null
-- group by query_name
