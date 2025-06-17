# Write your MySQL query statement below
select s.user_id, round(avg(if(action = 'confirmed', 1, 0)), 2) confirmation_rate
from Signups s
left join Confirmations c
on s.user_id = c.user_id
group by s.user_id 















-- select s.user_id,round(if(count(c.user_id) = 0, 0, avg(c.action = 'confirmed')), 2) as confirmation_rate 
-- from Signups s 
-- left join Confirmations c on s.user_id = c.user_id
-- group by s.user_id