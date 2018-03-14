
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE procTestRuns 
@tableID int,
@viewID int
AS
BEGIN
	SET NOCOUNT ON;
	
	DECLARE @testID int
    DECLARE @ds DATE
	DECLARE @de DATE
	DECLARE @procName VARCHAR(50)

	SET @ds = GETDATE()
	--delete first
	SET @procName = 'delete'+CONVERT(VARCHAR(5),@tableID)
	EXEC @procName
	--insert
	SET @procName = ''
	SET @procName = 'insert'+CONVERT(VARCHAR(5),@tableID)
	EXEC @procName
	--select view
	SET @procName = ''
	SET @procName = 'view'+CONVERT(VARCHAR(5),@viewID)
	EXEC @procName

	SET @de = GETDATE()
	INSERT INTO dbo.TestRuns (TestRunID,Description,StartAt,EndAt) VALUES (@testID,'description',@ds,@de)

END
GO
