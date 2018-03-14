/*    ==Scripting Parameters==

    Source Server Version : SQL Server 2017 (14.0.1000)
    Source Database Engine Edition : Microsoft SQL Server Express Edition
    Source Database Engine Type : Standalone SQL Server

    Target Server Version : SQL Server 2017
    Target Database Engine Edition : Microsoft SQL Server Standard Edition
    Target Database Engine Type : Standalone SQL Server
*/

USE [Skate_Shop]
GO
/****** Object:  StoredProcedure [dbo].[procTestRunsViews]    Script Date: 12/13/2017 1:47:25 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	procedure for testRunViews
-- =============================================
ALTER PROCEDURE [dbo].[procTestRunsViews]
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	DECLARE @ds1 DATE
	DECLARE @de1 DATE
	SET @ds1 = GETDATE()
	SELECT * FROM View_1
	SET @de1 = GETDATE()

	DECLARE @testRunID int
	SET @testRunID = 1
	INSERT INTO dbo.TestRunViews (ViewID,StartAt,EndAt) VALUES (1,@ds1,@de1)

	DECLARE @ds2 DATE
	DECLARE @de2 DATE
	SET @ds2 = GETDATE()
	SELECT * FROM View_2
	SET @de2 = GETDATE()

	SET @testRunID = @testRunID + 1
	INSERT INTO dbo.TestRunViews (TestRunID,ViewID,StartAt,EndAt) VALUES (@testRunID,2,@ds2,@de2)

	DECLARE @ds3 DATE
	DECLARE @de3 DATE
	SET @ds3 = GETDATE()
	SELECT * FROM View_3
	SET @de3 = GETDATE()

	SET @testRunID = @testRunID + 1
	INSERT INTO dbo.TestRunViews (TestRunID,ViewID,StartAt,EndAt) VALUES (@testRunID,1,@ds3,@de3)

END
