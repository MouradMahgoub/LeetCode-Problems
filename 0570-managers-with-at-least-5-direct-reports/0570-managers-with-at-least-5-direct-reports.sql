# Write your MySQL query statement below

select e1.name
from Employee e1
join Employee e2
on e1.id = e2.managerId
group by e1.id
having count(*) >= 5  












-- select e1.name 
-- from Employee e1 join Employee e2
-- on e1.id = e2.managerId
-- group by e2.managerId
-- having count(e2.managerId) >= 5

-- select name from Employee
-- where id in (
--     select managerId from Employee
--     group by managerId
--     having count(*) >= 5
-- )

-- select name 
-- from Employee
-- join (
--     select managerId
--     from Employee 
--     group by managerId 
--     having count(managerId) >= 5
-- ) manager 
-- on Employee.id = manager.managerId
