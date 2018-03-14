-- 1.modify the type of a column
ALTER TABLE Sites
ALTER COLUMN Address varchar(100) NOT NULL;

--2.reverse
ALTER TABLE Sites
ALTER COLUMN Address varchar(50);

--3.add default constraint
ALTER TABLE Managers
ADD CONSTRAINT df_0 DEFAULT 0 FOR Experience;

--4.reverse (remove default constraint)
ALTER TABLE Managers
DROP CONSTRAINT df_0;

--5.create a new table
CREATE TABLE Orders(
Oid int NOT NULL PRIMARY KEY,
ShoesId int,
Sk8Id int
);

--6.delete table
DROP TABLE Orders;

--7.add a column
ALTER TABLE Managers
ADD Dob date;

--8.delete column
ALTER TABLE Managers
DROP COLUMN Dob;

--9.create foreign key constraint
ALTER TABLE Orders
ADD CONSTRAINT fk_order_shoes FOREIGN KEY(ShoesId) REFERENCES Shoes(ShoesId);

--10.remove foreign key constraint
ALTER TABLE Orders
DROP CONSTRAINT fk_order_shoes;