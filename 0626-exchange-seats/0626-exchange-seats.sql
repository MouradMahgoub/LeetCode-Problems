# Write your MySQL query statement below
select 
    if(id = (select max(id) from Seat) and mod(id, 2) = 1, id, 
        if(mod(id, 2) = 0, id-1, id+1)) as id, student
from Seat
order by id
    -- case
    --     when mod(id, 2) = 1 and id = (select max(id) from Seat)
    --         then id
    --     when mod(id, 2) = 0
    --         then id-1
    --     else id+1
    -- end as id, student