-- List all orders along with the delivery employee’s name.
select o.order_id, o.customer_id, c.name as customer_name, c.city as delivery_address, o.order_date, d.delivery_id, d.delivery_date, d.emp_id, e.name as emp_name from Orders o
left join Deliveries d on o.order_id = d.order_id
left join Employees e on e.emp_id = d.emp_id
left join Customers c on c.customer_id = o.customer_id

-- Display all customers, their orders, and the delivery employee who handled them (even if some parts are missing).
select o.order_id, COALESCE(o.customer_id, c.customer_id) AS customer_id, c.name as customer_name, c.city as delivery_address, o.order_date, d.delivery_id, d.delivery_date, COALESCE(d.emp_id, e.emp_id) AS emp_id, e.name as emp_name from Orders o
full outer join Deliveries d on o.order_id = d.order_id
full outer join Employees e on e.emp_id = d.emp_id
full outer join Customers c on c.customer_id = o.customer_id

-- Find employees who delivered orders to customers in the same city.
select e.emp_id, e.name as emp_name, c.city, e.city as e_city from Employees e
inner join Deliveries d on d.emp_id = e.emp_id
inner join Orders o on o.order_id = d.order_id
inner join Customers c on c.customer_id = o.customer_id
where c.city = e.city

-- Show each employee and how many total products they delivered (via joins across all related tables).
-- List all orders along with the delivery employee’s name.
select o.order_id, o.customer_id, c.name as customer_name, c.city as delivery_address, o.order_date, d.delivery_id, d.delivery_date, d.emp_id, e.name as emp_name from Orders o
left join Deliveries d on o.order_id = d.order_id
left join Employees e on e.emp_id = d.emp_id
left join Customers c on c.customer_id = o.customer_id

-- Display all customers, their orders, and the delivery employee who handled them (even if some parts are missing).
select o.order_id, COALESCE(o.customer_id, c.customer_id) AS customer_id, c.name as customer_name, c.city as delivery_address, o.order_date, d.delivery_id, d.delivery_date, COALESCE(d.emp_id, e.emp_id) AS emp_id, e.name as emp_name from Orders o
full outer join Deliveries d on o.order_id = d.order_id
full outer join Employees e on e.emp_id = d.emp_id
full outer join Customers c on c.customer_id = o.customer_id

-- Find employees who delivered orders to customers in the same city.
select e.emp_id, e.name as emp_name, c.city, e.city as e_city from Employees e
inner join Deliveries d on d.emp_id = e.emp_id
inner join Orders o on o.order_id = d.order_id
inner join Customers c on c.customer_id = o.customer_id
where c.city = e.city

-- Show each employee and how many total products they delivered (via joins across all related tables).
select e.emp_id, e.name as emp_name, coalesce(sum(od.quantity), 0) AS total_products_delivered from Employees e
left join Deliveries d on d.emp_id = e.emp_id
left join Orders o on o.order_id = d.order_id
left join OrderDetails od on od.order_id = o.order_id
group by e.emp_id, emp_name