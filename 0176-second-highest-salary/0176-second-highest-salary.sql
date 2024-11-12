# Write your MySQL query statement below
-- select min(salary) AS SecondHighestSalary
-- from (
--     select distinct salary 
--     from employee
--     order by salary desc
--     limit 2
-- ) t1

select distinct max(salary) AS SecondHighestSalary
from Employee e1
where salary not in (
    select max(salary)
    from Employee e2
)
