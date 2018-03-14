USE Skate_Shop
GO

DECLARE @NoOfRows int
DECLARE @n int
DECLARE @name VARCHAR(30)

SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables
				/*
						INNER JOIN dbo.TestTables tt ON
						dbo.Tables.TableID = tt.TableID
						WHERE tt.TableID = 1
				*/
				WHERE dbo.TestTables.Position = 1
SET @n=1

WHILE @n<@NoOfRows
BEGIN
	SET @name = 'City'+ CONVERT(VARCHAR(5),@n)
	INSERT INTO Cities (Name,Country) VALUES (@name,'Egypt')
	SET @n = @n+1
END