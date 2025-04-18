# Write your MySQL query statement below
select person_name from Queue q1 
where (select sum(weight) from Queue q2 where q2.turn <= q1.turn) <= 1000
order by turn desc
limit 1

-- select t1.person_name from Queue t1 
-- join Queue t2 on t1.turn >= t2.turn
-- group by t1.turn
-- having sum(t2.weight) <= 1000
-- order by sum(t2.weight) desc
-- limit 1