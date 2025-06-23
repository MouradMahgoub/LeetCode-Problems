select a.visited_on, sum(b.amount) amount, round(sum(b.amount)/7, 2) average_amount 
from (select visited_on, sum(amount) amount from Customer group by visited_on) a
join (select visited_on, sum(amount) amount from Customer group by visited_on) b
on datediff(a.visited_on, b.visited_on) between 0 and 6
group by a.visited_on
having count(b.visited_on) = 7
