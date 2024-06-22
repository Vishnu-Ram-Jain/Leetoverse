# Write your MySQL query statement below
select e.employee_id from Employees as e where e.salary < 30000 
and
e.manager_id not in
(select z.employee_id from Employees as z) 
order by employee_id ;