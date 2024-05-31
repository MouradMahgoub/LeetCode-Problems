# Write your MySQL query statement below
select machine_id, ROUND(AVG(end_time - start_time), 3) processing_time 
from
(
    select A1.machine_id, A1.timestamp start_time, A2.timestamp end_time
    from Activity A1
    join Activity A2
    on A1.process_id = A2.process_id AND A1.machine_id = A2.machine_id
    where A1.activity_type = 'start' AND A2.activity_type = 'end'
) TT
group by machine_id;
