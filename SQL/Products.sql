-- Products Table
CREATE TABLE Products (
    product_id INT PRIMARY KEY,
    name VARCHAR(50),
    category VARCHAR(30),
    price DECIMAL(10,2)
);

INSERT INTO Products VALUES
(1, 'Laptop', 'Electronics', 70000),
(2, 'Mouse', 'Electronics', 500),
(3, 'Book', 'Stationery', 300),
(4, 'T-shirt', 'Clothing', 800),
(5, 'Headphones', 'Electronics', 2000);