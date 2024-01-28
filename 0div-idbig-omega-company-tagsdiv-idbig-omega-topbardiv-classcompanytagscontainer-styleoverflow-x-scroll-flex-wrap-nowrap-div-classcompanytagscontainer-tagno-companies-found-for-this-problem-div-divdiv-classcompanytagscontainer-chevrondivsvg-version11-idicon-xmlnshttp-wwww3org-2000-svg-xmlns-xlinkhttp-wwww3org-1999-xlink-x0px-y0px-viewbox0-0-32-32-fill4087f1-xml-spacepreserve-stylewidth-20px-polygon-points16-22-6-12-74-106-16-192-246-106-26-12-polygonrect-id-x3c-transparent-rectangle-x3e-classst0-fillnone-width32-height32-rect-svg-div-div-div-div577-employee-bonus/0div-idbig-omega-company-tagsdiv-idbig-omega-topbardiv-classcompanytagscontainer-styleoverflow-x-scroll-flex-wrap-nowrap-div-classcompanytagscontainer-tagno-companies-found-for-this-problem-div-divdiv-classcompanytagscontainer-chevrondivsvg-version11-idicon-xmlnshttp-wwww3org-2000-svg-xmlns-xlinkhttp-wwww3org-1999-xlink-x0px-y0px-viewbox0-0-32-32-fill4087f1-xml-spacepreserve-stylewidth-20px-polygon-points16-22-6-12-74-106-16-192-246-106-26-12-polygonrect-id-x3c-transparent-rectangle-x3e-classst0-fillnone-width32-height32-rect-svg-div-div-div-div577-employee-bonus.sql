# Write your MySQL query statement below

select Employee.name , Bonus.bonus from Employee LEFT JOIN Bonus ON Employee.empId = Bonus.empId where Bonus.bonus<1000 or Bonus.bonus is null;