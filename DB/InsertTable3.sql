USE Skate_Shop
GO

DECLARE @NoOfRows int
DECLARE @n int
DECLARE @name VARCHAR(30)

DECLARE @pk1 int
DECLARE @pk2 int
SELECT TOP 1 @pk1 = ShoesId FROM Shoes
SELECT TOP 1 @pk2 = Sid FROM Shops
DECLARE @row_number1 int
DECLARE @row_number2 int
DECLARE @max1 int
DECLARE @max2 int

SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				WHERE dbo.TestTables.Position = 3
SET @n=1
SET @row_number2 = 1
SET @row_number2 = 1
/*
WHILE @n<@NoOfRows
BEGIN
/*
	SET @row_number1 = ROW_NUMBER() OVER (ORDER BY ShoesId)
	SET @row_number1 = ROW_NUMBER() OVER (ORDER BY Sid)
	SELECT TOP 1 @pk1 = ShoesId FROM (SELECT ShoesId FROM Shoes WHERE ROW_NUMBER() = @row_number1)
	INSERT INTO ShopsShoes (Sid,ShoesId) VALUES (@pk1,@pk2)
*/
	SELECT @pk1 = Shops.Sid
	FROM (SELECT ROW_NUMBER() OVER(ORDER BY Sid) AS rown,Sid
	FROM Shops) Shops
	WHERE rown = 2
*/
	SELECT @max1 = COUNT(*) FROM Shops
	SELECT @max2 = COUNT(*) FROM Shoes
	WHILE @row_number1 < @max1 AND @row_number2 < @max2 AND @n<@NoOfRows
	BEGIN
		SELECT @pk1 = Shops.Sid
		FROM (SELECT ROW_NUMBER() OVER(ORDER BY Sid) AS rown,Sid
		FROM Shops) Shops
		WHERE rown = @row_number1

		SET @row_number1 = @row_number1 + 1

		SELECT @pk2 = Shoes.ShoesId
		FROM (SELECT ROW_NUMBER() OVER(ORDER BY ShoesId) AS rown,ShoesId
		FROM Shoes) Shoes
		WHERE rown = @row_number2

		INSERT INTO ShopsShoes (Sid,ShoesId) VALUES (@pk1,@pk2)

		SET @row_number2 = @row_number2 + 1
		SET @n = @n+1
	END