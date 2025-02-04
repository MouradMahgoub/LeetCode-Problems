# Write your MySQL query statement below
select name 
from Employee
join (
    select managerId
    from Employee 
    group by managerId 
    having count(managerId) >= 5
) manager 
on Employee.id = manager.managerId
