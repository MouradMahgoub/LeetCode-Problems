# Write your MySQL query statement below
SELECT distinct author_id AS id
FROM Views
Where author_id = viewer_id
ORDER BY author_id;