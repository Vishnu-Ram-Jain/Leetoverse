# Write your MySQL query statement below
-- select salary as SecondHighestSalary from Employee 
-- order by salary desc 
-- limit 1,1;
select max(salary) as SecondHighestSalary from Employee
where salary <> (select max(salary) from Employee);