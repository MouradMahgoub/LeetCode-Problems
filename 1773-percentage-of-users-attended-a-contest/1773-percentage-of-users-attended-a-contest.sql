select contest_id, round(count(*)*100/(select count(*) from Users), 2) percentage
from Users U
join Register R on U.user_id = R.user_id
group by contest_id
order by percentage desc, contest_id asc