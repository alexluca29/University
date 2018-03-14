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
/****** Object:  StoredProcedure [dbo].[main]    Script Date: 11/16/2017 5:18:29 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Description:	takes the db to a version given as parameter
-- =============================================
ALTER PROCEDURE [dbo].[main]
@vers INT
AS
BEGIN
	DECLARE @currentVers INT

	SET NOCOUNT ON;
	SELECT TOP 1 @currentVers = vid
	FROM Version;

	IF @vers <0 OR @vers >5
	BEGIN
		PRINT 'Not a valid version'
		RETURN
	END

	IF @vers = @currentVers
	BEGIN
		PRINT 'This is the current version.Nothing to modify'
		RETURN
	END

	DECLARE @command VARCHAR(50)


	WHILE @currentVers < @vers
	 BEGIN
		SET @command = 'up' + CONVERT(VARCHAR(5),@currentVers+1)
		EXEC @command
		SET @currentVers = @currentVers + 1
	 END

	 WHILE @currentVers > @vers
	  BEGIN
	  	SET @command = 'down' + CONVERT(VARCHAR(5),@currentVers)
		EXEC @command
		SET @currentVers = @currentVers - 1
	  END

	UPDATE Version
	SET vid = @currentVers
END

