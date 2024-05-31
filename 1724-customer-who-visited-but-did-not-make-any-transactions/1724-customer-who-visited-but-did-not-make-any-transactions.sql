# Write your MySQL query statement below
select customer_id, count(V.visit_id) count_no_trans
from Visits V
left join Transactions T
on V.visit_id = T.visit_id
where transaction_id is NULL
group by customer_id;