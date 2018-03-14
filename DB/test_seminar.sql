
use testSeminar
GO

IF OBJECT_ID('RoutesStations','U') IS NOT NULL
	DROP TABLE RoutesStations
IF OBJECT_ID('Stations','U') IS NOT NULL
	DROP TABLE Stations
IF OBJECT_ID('Routes','U') IS NOT NULL
	DROP TABLE [Routes] --might be reserved
IF OBJECT_ID('Trains','U') IS NOT NULL
	DROP TABLE Trains
IF OBJECT_ID('TrainTypes','U') IS NOT NULL
	DROP TABLE TrainTypes


create table TrainTypes
	(TTID tinyint primary key identity(1,1),
	TTDescription Varchar(500))

create table Trains
	(TID smallint primary key identity(1,1),
	TName Varchar(500),
	TTID tinyint references TrainTypes(TTID))


create table [Routes]
	(RID smallint primary key identity(1,1),
	RName Varchar(500) unique,
	TID smallint references Trains(TID))


create table Stations
	([SID] smallint primary key identity(1,1),
	SName Varchar(500) unique)


create table RoutesStations
	(RID smallint references [Routes](RID),
	SID smallint references Stations([SID]),
	Arrival TIME,
	Departure TIME)


insert TrainTypes values('regio'),('interregio')
insert Trains values('t1',1),('t2',1),('t3',1)
insert [Routes] values('r1',1),('r2',2),('r3',3)
insert Stations values('s1'),('s2'),('s3')
insert RoutesStations(RID,[SID],Arrival,Departure) VALUES
 (1,1,'9:50am','10:00am'),(1,2,'10:10am','10:20am'),(1,3,'11:00am','11:10am'),
 (2,1,'9:40am','9:50am'),							(2,3,'12:00pm','12:10pm'),
						(3,2,'10:05am','10:25am')
GO

select *from TrainTypes
select *from Trains
select *from [Routes]
select *from RoutesStations
select * from Stations
go

create procedure uspStationOnRoute @RName varchar(50),@Sname varchar(50),@ATime TIME,@DTime Time
AS
	declare @RID smallint = (select RID from [Routes] where RName=@RName),
		@SID smallint = (select [SID] from STations Where SName = @Sname)
	if exists (select * from RoutesStations where RID=@RID and [SID] = @SID)
		UPDATE RoutesStations
		set Arrival=@ATime,Departure=@DTime
		where RID = @RID and [SID] = SID
	else --daca select nu ret nimic
		insert RoutesStations(RID,[SID],Arrival,Departure) values
		(@RID,@SID,@ATime,@DTime)
GO

SELECT *from RoutesStations

EXEC uspStationOnRoute @RName='r3',@SName='s1',@ATime='14:01',@DTime='14:10'

CREATE VIEW vRoutesWithAllStations
AS
	--rutele care trec prin toate statiile
	select R.RName
	from [Routes] R
	where not exists
		(select s.[SID]
		FROM Stations S
		except
		select RS.[SID]
		from RoutesStations RS
		Where RS.RID = R.RID)
go
select * from vRoutesWithAllStations

--function
--v1 - cu parametri timp exact
--v2 - fara param - pt toata ziua
create function ufStationWithOverlappingRoutes()
returns table
as
	return
		select S.SName
		from Stations S
		where S.[SID] IN
		(
			select RS1.[SID]
			from RoutesStations RS1 inner join RoutesStations RS2 on RS1.[SID] = RS2.[SID] and RS1.RID < RS2.RID
				AND RS1.Arrival <= RS2.Departure AND RS1.Departure >= RS2.Arrival
		)
GO
select * from ufStationWithOverlappingRoutes()
select * from RoutesStations