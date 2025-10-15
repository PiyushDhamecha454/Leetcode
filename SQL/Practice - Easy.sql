-- Show all customers and their corresponding orders (only those who placed an order).
select * from Customers inner join Orders on Customers.customer_id = Orders.customer_id

-- List all customers and their orders — include customers even if they haven’t placed any.
select * from Customers left join Orders on Customers.customer_id = Orders.customer_id

-- Find all orders and their customers — include orders even if the customer doesn’t exist.
select * from Customers right join Orders on Customers.customer_id = Orders.customer_id

-- Display all customers and orders, even if one of them doesn’t match.
select * from Customers full outer join Orders on Customers.customer_id = Orders.customer_id

-- List all possible customer–product combinations (every customer with every product).
select * from Customers cross join Products