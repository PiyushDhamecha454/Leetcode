-- Show customer names and total order amounts for each order.
select c.name, sum(o.amount) from Customers c inner join Orders o on c.customer_id = o.customer_id group by c.name

-- Find all orders that include at least one Electronics product.
select o.order_id, c.name as Customer_Name, o.order_date, o.amount, p.product_id, p.name as Product_Name, p.category, p.price, op.quantity from Orders o
inner join Customers c on o.customer_id = c.customer_id
inner join OrderDetails op on  o.order_id = op.order_id
inner join Products p on op.product_id = p.product_id
where op.quantity > 0 and p.category = 'Electronics'

-- Display all products and the total quantity sold (if any).
select p.name as product_name, coalesce(sum(op.quantity), 0) as quantity_sold from Products p left join OrderDetails op on p.product_id = op.product_id group by p.name order by quantity_sold

-- List customers who have never placed an order.
select c.customer_id, c.name as customer_name from Customers c left join Orders o on c.customer_id = o.customer_id where o.order_id is null

-- Find the names of customers who have bought more than one product in a single order.
select c.name as customer_name, o.order_id, count(op.product_id) as product_quantity from Customers c
inner join Orders o on c.customer_id = o.customer_id
inner join OrderDetails op on o.order_id = op.order_id
group by o.order_id, c.name having count(op.product_id) > 1

-- List all unique product names purchased by customers from ‘Delhi’.
select distinct p.name from Products p
inner join OrderDetails od on od.product_id = p.product_id
inner join Orders o on o.order_id = od.order_id
inner join Customers c on c.customer_id = o.customer_id
where c.city = 'Delhi'

-- Show each customer’s latest order date.
select c.customer_id, c.name, max(o.order_date) as last_order_date from Customers c
inner join Orders o on o.customer_id = c.customer_id group by c.customer_id, c.name