-- OrderDetails Table (Many-to-Many between Orders and Products)
CREATE TABLE OrderDetails (
    order_id INT,
    product_id INT,
    quantity INT,
    PRIMARY KEY (order_id, product_id),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

INSERT INTO OrderDetails VALUES
(101, 1, 1),
(101, 2, 2),
(102, 3, 1),
(103, 4, 3),
(104, 5, 1),
(105, 1, 1);