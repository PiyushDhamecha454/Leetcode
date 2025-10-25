# Write your MySQL query statement below
select 
    round(
        sum(order_date = customer_pref_delivery_date) * 100 / count(*),
        2
    ) AS immediate_percentage
    from
(
    select 
        customer_id,
        min(order_date) AS order_date,
        min(customer_pref_delivery_date) AS customer_pref_delivery_date
    from Delivery
    group by customer_id
) as first_orders