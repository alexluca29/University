USE Skate_Shop
GO

DECLARE @noOfRows int
SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				WHERE dbo.TestTables.Position = 5

DELETE TOP (@noOfRows)
FROM Shops