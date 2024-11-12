# Write your MySQL query statement below
select max(e1.salary) AS SecondHighestSalary
from Employee e1
join Employee e2
where e1.salary < e2.salary

-- select distinct max(salary) AS SecondHighestSalary
-- from Employee e1
-- where salary not in (
--     select max(salary)
--     from Employee e2
-- )
