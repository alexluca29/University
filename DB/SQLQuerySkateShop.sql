Create database Skate_Shop
GO
use Skate_Shop
GO

CREATE TABLE Cities
(Cid INT PRIMARY KEY IDENTITY,
Name varchar(50),
Country varchar(50)
)

CREATE TABLE Shops
(Sid INT PRIMARY KEY IDENTITY,
Name varchar(50),
Cid INT FOREIGN KEY REFERENCES Cities(Cid)
)

CREATE TABLE Sites
(Name varchar(50),
Address varchar(50),
SiteId INT FOREIGN KEY REFERENCES Shops(Sid), 
CONSTRAINT pk_ShopsSites PRIMARY KEY(SiteId)
)

CREATE TABLE Managers
(Mid INT FOREIGN KEY REFERENCES Shops(Sid) ,
Name varchar(50) NOT NULL,
Experience int,
CONSTRAINT pk_ShopsManagers PRIMARY KEY(Mid)
)


CREATE TABLE Brands
(Bid INT PRIMARY KEY IDENTITY,
Name varchar(50),
Fans INT,
)

CREATE TABLE Skateboards
(Sk8Id INT PRIMARY KEY IDENTITY,
Name varchar(50),
Price int,
Size int,
Bid INT FOREIGN KEY REFERENCES Brands(Bid)
)

CREATE TABLE Components
(Cid INT PRIMARY KEY IDENTITY,
Name varchar(50),
Price int,
Sk8Id INT FOREIGN KEY REFERENCES Skateboards(Sk8Id)
)

CREATE TABLE ShopsSkates
(Sid INT FOREIGN KEY REFERENCES Shops(Sid),
Sk8Id INT FOREIGN KEY REFERENCES Skateboards(Sk8Id),
CONSTRAINT pk_Skates PRIMARY KEY (Sid,Sk8Id)
)


CREATE TABLE Shoes
(ShoesId INT PRIMARY KEY IDENTITY,
Name varchar(50),
Size int,
Bid INT FOREIGN KEY REFERENCES Brands(Bid)
)

CREATE TABLE ShopsShoes
(Sid INT FOREIGN KEY REFERENCES Shops(Sid),
ShoesId INT FOREIGN KEY REFERENCES Shoes(ShoesId)
CONSTRAINT pk_ShoesS PRIMARY KEY (Sid,ShoesId)
)