# Write your MySQL query statement below
select unique_id, name
from EmployeeUNI U
right join Employees E
on U.id = E.id;