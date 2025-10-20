CREATE TABLE Deliveries (
    delivery_id INT PRIMARY KEY,
    order_id INT,
    emp_id INT,
    delivery_date DATE,
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (emp_id) REFERENCES Employees(emp_id)
);

INSERT INTO Deliveries VALUES
(1, 101, 1, '2025-10-03'),
(2, 102, 2, '2025-10-12'),
(3, 103, 2, '2025-10-04'),
(4, 104, 3, '2025-10-06');

select * from Deliveries