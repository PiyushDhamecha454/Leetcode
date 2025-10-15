-- Orders Table
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    amount DECIMAL(10,2),
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);

INSERT INTO Orders VALUES
(101, 1, '2025-10-01', 1200.00),
(102, 1, '2025-10-10', 1500.00),
(103, 2, '2025-10-02', 800.00),
(104, 3, '2025-10-04', 600.00),
(105, 5, '2025-10-05', 900.00);
-- (105, 6, '2025-10-05', 900.00);