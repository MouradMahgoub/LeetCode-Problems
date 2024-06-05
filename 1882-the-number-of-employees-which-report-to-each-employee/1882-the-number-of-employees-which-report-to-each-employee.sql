# Write your MySQL query statement below
select managers.employee_id, managers.name, count(employees.reports_to) reports_count, round(avg(employees.age)) average_age
from Employees managers join Employees employees on managers.employee_id = employees.reports_to
group by managers.employee_id
order by managers.employee_id
