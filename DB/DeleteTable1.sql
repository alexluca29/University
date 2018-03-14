USE Skate_Shop
GO

DECLARE @noOfRows int
SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				WHERE dbo.TestTables.Position = 4

DELETE TOP (@noOfRows)
FROM Shops
DELETE TOP (@noOfRows)
FROM Cities