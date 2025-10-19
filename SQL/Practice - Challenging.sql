-- List all customer ids who ordered something on the same date as another customer.
select distinct o.customer_id from Orders o
join Orders p on p.order_date = o.order_date where p.order_id <> o.order_id
order by o.customer_id

-- List all customer ids with names who ordered something on the same date as another customer.
select distinct o.customer_id, c.name from Orders o
join Orders p on p.order_date = o.order_date and p.order_id <> o.order_id
join Customers c on o.customer_id = c.customer_id
order by o.customer_id

-- Find all product categories bought by customers from each city.
select distinct p.category, c.city from Products p 
inner join OrderDetails od on p.product_id = od.product_id
inner join Orders o on o.order_id = od.order_id
inner join Customers c on c.customer_id = o.customer_id

-- Display each product with the number of distinct customers who purchased it.
select p.name, count(distinct(c.customer_id)) as customer_count from Products p
left join OrderDetails od on p.product_id = od.product_id
left join Orders o on o.order_id = od.order_id
left join Customers c on c.customer_id = o.customer_id
group by p.name order by customer_count desc

-- Show each customer and the number of orders they made, even if they have none.
select c.customer_id, c.name, count(o.order_id) as number_of_orders from Customers c
left join Orders o on o.customer_id = c.customer_id
group by c.customer_id, c.name order by o.order_id