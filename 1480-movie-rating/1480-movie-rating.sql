# Write your MySQL query statement below
(
    select name as results
    from Users join MovieRating using(user_id)
    group by user_id
    order by count(*) desc, name
    limit 1
)
union all
(
    select title
    from Movies join MovieRating using(movie_id)
    where year(created_at) = 2020 and month(created_at) = 2
    group by movie_id
    order by avg(rating) desc, title
    limit 1
)
