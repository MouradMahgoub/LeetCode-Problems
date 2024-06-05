# Write your MySQL query statement below
select st.student_id, student_name, s.subject_name, count(e.subject_name) attended_exams
from Students st
cross join Subjects s
left join Examinations e
on e.student_id = st.student_id and e.subject_name = s.subject_name
group by st.student_id, s.subject_name
order by st.student_id, s.subject_name