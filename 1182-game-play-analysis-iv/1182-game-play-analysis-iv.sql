# Write your MySQL query statement below
select round(count(*)/(select count(distinct A3.player_id) from Activity A3), 2) fraction
from Activity A1
where (A1.player_id, date_sub(A1.event_date, interval 1 day)) in 
    (
        select A2.player_id, min(A2.event_date)
        from Activity A2
        group by A2.player_id
    )