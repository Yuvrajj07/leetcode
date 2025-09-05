-- # Write your MySQL query statement below

-- select (select distinct(salary) from Employee  e1 where 1=(select count(distinct(salary)) from Employee e2 where e1.salary>e2.salary)) as  SecondHighestSalary ;

select max(salary) as SecondHighestSalary  from Employee where salary <( select max(salary) from employee);