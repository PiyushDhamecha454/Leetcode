CREATE TABLE Employees (
    emp_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(50)
);

INSERT INTO Employees VALUES
(1, 'Rita', 'Delhi'),
(2, 'Sam', 'Mumbai'),
(3, 'Tara', 'Pune');

select * from employees