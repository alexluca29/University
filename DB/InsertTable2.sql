USE Skate_Shop
GO

DECLARE @NoOfRows int
DECLARE @n int
DECLARE @name VARCHAR(30)

DECLARE @fk int
DECLARE @fk1 int
SELECT TOP 1 @fk1 = Cid FROM Cities

SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				WHERE dbo.TestTables.Position = 2
SET @n=1

WHILE @n<@NoOfRows
BEGIN
	SET @name = 'Shop'+ CONVERT(VARCHAR(5),@n)
	INSERT INTO Shops (Name,Cid) VALUES (@name,@fk1)
	SET @n = @n+1
END