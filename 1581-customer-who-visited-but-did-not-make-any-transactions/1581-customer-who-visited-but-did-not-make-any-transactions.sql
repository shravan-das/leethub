# Write your MySQL query statement below

select visits.customer_id , count(visits.visit_id) as count_no_trans from visits LEFT JOIN Transactions on visits.visit_id = Transactions.visit_id where Transactions.visit_id  is NULL group by visits.customer_id;