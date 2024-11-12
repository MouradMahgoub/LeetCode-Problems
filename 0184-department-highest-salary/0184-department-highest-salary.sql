# Write your MySQL query statement below
select d.name as Department, e.name as Employee, Salary
from Employee e, Department d
where e.departmentId = d.id
and salary = 
    (
        select max(salary) 
        from Employee e2
        where e2.departmentId = d.id
    )
