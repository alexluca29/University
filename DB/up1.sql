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
/****** Object:  StoredProcedure [dbo].[up1]    Script Date: 11/16/2017 4:55:59 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

--Description: modify the type of a column

ALTER PROCEDURE [dbo].[up1] 
AS
BEGIN
	SET NOCOUNT ON;

	ALTER TABLE Sites
	ALTER COLUMN Address varchar(100) NOT NULL;
	PRINT 'Version update. Current version 1'
END
