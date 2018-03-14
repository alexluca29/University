USE Skate_Shop
GO

DECLARE @noOfRows int
SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				WHERE dbo.TestTables.Position = 5

DELETE TOP (@noOfRows)
FROM ShopsShoes
DELETE TOP (@noOfRows)
FROM Shoes
DELETE FROM Sites
DELETE FROM Managers
DELETE FROM ShopsSkates
DELETE TOP (@noOfRows)
FROM Shops