use Exam
go

IF OBJECT_ID('Cookies','U') IS NOT NULL
	DROP TABLE Cookies
IF OBJECT_ID('CookiesTypes','U') IS NOT NULL
	DROP TABLE CookiesTypes
IF OBJECT_ID('Ingredients','U') IS NOT NULL
	DROP TABLE Ingredients
IF OBJECT_ID('CookiesIngredients','U') IS NOT NULL
	DROP TABLE CoockiesIngredients
IF OBJECT_ID('Orders','U') IS NOT NULL
	DROP TABLE Orders
IF OBJECT_ID('Clients','U') IS NOT NULL
	DROP TABLE Clients


create table CookiesTypes
(CTID int primary key identity(1,1),
[Type] varchar(50),
AvgWeight int,
PricePerKilo int,
[Description] varchar(50)
)

create table Cookies
(CID int primary key identity(1,1),
CName varchar(50),
Price int,
ExpDate DATE,
CTID int references CookiesTypes(CTID)
)
go

create table Ingredients
(IID int primary key identity(1,1),
IName varchar(50),
Quantity int,
ExpDate DATE
)
go

create table CookiesIngredients
(CID int references Cookies(CID),
IID int references Ingredients(IID),
QuantiyUsed int,
Principal int
)
go



create table Clients
(CLID int primary key identity(1,1),
CLName varchar(50),
Age int,
Budget int
--OID int references Orders(OID)
)
go

create table Orders
(OID int primary key identity(1,1),
DateOfBuying DATE,
ODescription varchar(50),
CID int references Cookies(CID),
CLID int references Clients(CLID)
)
go

insert CookiesTypes values ('birthday cake',10,2,'d1'),('cheese cake',2,1,'d2')
go
insert Cookies values ('c1',1,'2018-01-12',1),('c2',2,'2018-01-13',2),('c3',1,'2018-11-11',1)
go
insert Ingredients values ('i1',20,'2018-01-01'),('i2',10,'2018-02-15')
go
insert CookiesIngredients values (6,5,2,1),(7,5,3,0),(8,6,1,1)
go
insert Clients values ('cl1',66,33),('cl2',24,53),('cl3',13,12)
go
insert Orders values ('2018-01-10','desc1',6,1),('2018-01-04','desc2',7,1)
go

select * from CookiesTypes
select * from Cookies
select * from Ingredients
select * from CookiesIngredients
select * from Clients
select * from Orders
go

create procedure procAdd
@CName varchar(50),
@Price int,
@ExpDate DATE,
@CTID int,
@IName varchar(50),
@Quantity int,
@ExpDate2 DATE,
@QUsed int,
@Principal int
as
begin
	declare @cid int = (select CID from Cookies where CName=@CName)
	declare @iid int = (select IID from Ingredients where IName=@IName)
	if exists(select * from Cookies c inner join CookiesIngredients ci ON c.CID=ci.CID
									inner join Ingredients i ON ci.IID=i.IID
									where c.CName=@CName and i.IName=@IName)
		UPDATE CookiesIngredients
		set QuantiyUsed=@QUsed,Principal=@Principal
		where CID=@cid and IID=@iid
	else
		insert CookiesIngredients values (@cid,@iid,@QUsed,@Principal)
end
go


exec procAdd 'c1',10,'2018-02-03',2,'i1',4,'2018-01-06',1,1
go

select * from CookiesIngredients
go

create view viewCookies
as
	select c.CName
	from Cookies c
	where not exists
		(select i.IID
		FROM Ingredients i
		except
		select ci.IID
		from CookiesIngredients ci
		Where ci.CID = c.CID)

go

select * from viewCookies
go

create function func(@IID int)
returns table
as
	return 
		select cl.CLName
		from Clients cl inner join Orders o ON cl.CLID=o.OID
						inner join Cookies c ON o.CID=c.CID
						inner join CookiesIngredients ci ON c.CID = ci.CID
						inner join Ingredients i ON ci.IID=i.IID
		where i.IID=@IID
		group by cl.CLName,i.IID
		having i.IID=@IID and COUNT(i.IID)>1

go

select * from func(1)