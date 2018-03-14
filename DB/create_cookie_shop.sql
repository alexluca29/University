use CookieShop
go

IF OBJECT_ID('Cookies','U') IS NOT NULL
	DROP TABLE Cookies
IF OBJECT_ID('Boxes','U') IS NOT NULL
	DROP TABLE Boxes
IF OBJECT_ID('CoockieTBoxes','U') IS NOT NULL
	DROP TABLE CookieTBoxes 
IF OBJECT_ID('Clients','U') IS NOT NULL
	DROP TABLE Clients
IF OBJECT_ID('OrderTypes','U') IS NOT NULL
	DROP TABLE OrderTypes
IF OBJECT_ID('Orders','U') IS NOT NULL
	DROP TABLE Orders

create table CookieTypes
	(CTID int primary key identity(1,1),
	CTName varchar(50)
	)
go

create table Cookies
	(CID int primary key identity(1,1),
	CName varchar(50),
	Price int,
	Flavour int references CookieTypes(CTID)
	)
go

create table Boxes
	(BID int primary key identity(1,1),
	BName varchar(50)
	)
go

create table CookieTBoxes
	(CID int references Cookies(CID),
	BID int references Boxes(BID)
	)
go
create table Clients
	(CLID int primary key identity(1,1),
	CLName varchar(50),
	Phone varchar(50), 
	[Address] varchar(50)
	)
go
create table OrderTypes
	(OTID int primary key identity(1,1),
	OName varchar(50)
	)
go
create table Orders
	(CLID int references Clients(CLID),
	BID int references Boxes(BID),
	OTID int references OrderTypes(OTID)
	)

go

insert CookieTypes values ('vanilla'),('chocolate'),('hazelnuts')
go
insert Cookies values ('c1',10,1),('c2',12,2),('c3',10,1)
go
insert Boxes values ('b1'),('b2'),('b3')
go
insert CookieTBoxes values (1,1),(2,2),(3,1)
go
insert Clients values ('cl1','075','cernavoda2'),('cl2','123','dfgs'),('cl3','444','gsfd')
go
insert OrderTypes values ('shop'),('online')
go
insert Orders(CLID,BID,OTID) values (1,1,1),(2,2,2),(2,1,1)
go

select * from CookieTypes
select * from Cookies
select * from Boxes
select * from CookieTBoxes
select * from Clients
select * from OrderTypes
select * from Orders
go

alter procedure addBoxProc
@BID int,
@BoxName varchar(50),
@CookieType int,
@CookieName varchar(50),
@Price int,
@CID int
as
begin
	if exists (select * from Boxes b where b.BID = @BID)
		print 'Exista cutie'
	else
		if exists(select * from Cookies c where c.CID = @CID)
			print 'Exista cookie'
		else
		begin
			insert Boxes (BName) values (@BoxName)
			insert Cookies(CName,Price,Flavour) values (@CookieName,@Price,@CookieType)
			--pl cid si bid
			insert CookieTBoxes values (@CID,@BID)
		end
	
end

go


exec addBoxProc 4,'b4',1,'namer',3,6
go

create view mostExpensive
as
	select top 2 b.BName
	from Boxes b inner join Orders o on b.BID=o.BID
		inner join OrderTypes ot on o.OTID = ot.OTID 
	where ot.OName = 'online'
	order by (select c.Price from Cookies c inner join  CookieTBoxes cb on
				cb.CID = c.CID and cb.BID = b.BID)

go

select * from mostExpensive

go

