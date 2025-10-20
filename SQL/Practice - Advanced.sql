-- List all orders along with the delivery employee’s name.-- List all orders along with the delivery employee’s name.
select o.order_id, o.customer_id, c.name as customer_name, c.city as delivery_address, o.order_date, d.delivery_id, d.delivery_date, d.emp_id, e.name as emp_name from Orders o
left join Deliveries d on o.order_id = d.order_id
left join Employees e on e.emp_id = d.emp_id
left join Customers c on c.customer_id = o.customer_id

-- Display all customers, their orders, and the delivery employee who handled them (even if some parts are missing).
-- Find employees who delivered orders to customers in the same city.
-- Show each employee and how many total products they delivered (via joins across all related tables).
-- Display all customers, their orders, and the delivery employee who handled them (even if some parts are missing).
-- Find employees who delivered orders to customers in the same city.
-- Show each employee and how many total products they delivered (via joins across all related tables).