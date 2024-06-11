# Write your MySQL query statement below
# select student_id, student_name, subject_name, count(subject_name) 
# from Students as s, Subjects as s, Examinations as e 
# where student_id in 
# (select student_id from Examinations where )
select s.student_id, s.student_name, sub.subject_name, count(e.student_id) as attended_exams
from Students as s
cross join Subjects as sub
left join Examinations as e
on s.student_id = e.student_id and sub.subject_name = e.subject_name
group by 
s.student_id,
s.student_name,
sub.subject_name
order by s.student_id, sub.subject_name;

