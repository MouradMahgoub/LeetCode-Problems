# Write your MySQL query statement below
select distinct max(salary) AS SecondHighestSalary
from Employee e1
where salary < (
    select max(salary)
    from Employee e2
)