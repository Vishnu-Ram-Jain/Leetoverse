# Write your MySQL query statement below
select e2.employee_id, e2.name, count(e1.reports_to) as reports_count, round(avg(e1.age)) as average_age
from Employees as e1,Employees as e2
where e1.reports_to = e2.employee_id
group by e1.reports_to
order by e2.employee_id;
