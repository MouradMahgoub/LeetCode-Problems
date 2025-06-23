# Write your MySQL query statement below
select C1.visited_on, sum(C2.amount) amount, round(sum(C2.amount)/7, 2) average_amount
from (
    select distinct visited_on from Customer
    where date_sub(visited_on, interval 6 day) in (
        select visited_on from Customer
    )
) C1
join Customer C2 
on C2.visited_on between date_sub(C1.visited_on, interval 6 day) and C1.visited_on
group by C1.visited_on
