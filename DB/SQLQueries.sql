/*shoes order by fans desc
  DISTINCT 1*/
SELECT DISTINCT TOP 5 Shoes.Name,b.Fans
FROM Shoes
LEFT OUTER JOIN Brands AS b
ON Shoes.Bid = b.Bid
ORDER BY b.Fans DESC;

/*shops in care exista trase
  WHERE 1
  3 tabele 1*/
SELECT Shoes.Name,Shops.Name
FROM Shoes
LEFT OUTER JOIN ShopsShoes AS ss
ON Shoes.ShoesId = ss.ShoesId
LEFT OUTER JOIN Shops
ON ss.Sid = Shops.Sid
WHERE Shoes.Name Like 'Trase%';

/*order sk8 dupa pret
  3 tabele 2*/
SELECT sk.Name,sh.Name AS Shop_Name
FROM Skateboards AS sk
LEFT OUTER JOIN ShopsSkates AS ss
ON sk.Sk8Id = ss.Sk8Id
LEFT OUTER JOIN Shops AS sh
ON sh.Sid = ss.Sid
ORDER BY sk.Price;

/*fiecare deck in ce magazin e
 4 tabele 3
  where 2*/
SELECT comp.Name,sh.Name AS Shop
FROM Components comp
LEFT OUTER JOIN Skateboards sk
ON sk.Sk8Id = comp.Sk8Id
LEFT OUTER JOIN ShopsSkates ss
ON sk.Sk8Id = ss.Sk8Id
LEFT OUTER JOIN Shops sh
ON ss.Sid = sh.Sid
WHERE comp.Name LIKE '%Deck';

/*shoes size>42 and sk8 size>7
 many-to-many 1
 6 tabele 4
 where 3*/
SELECT Shops.Name AS Shop,Shoes.Name AS Shoes,sk.Name AS Skateboards
FROM Shoes
RIGHT OUTER JOIN ShopsShoes shsh
ON Shoes.ShoesId = shsh.ShoesId
RIGHT OUTER JOIN Shops
ON shsh.Sid = Shops.Sid
LEFT OUTER JOIN ShopsSkates shsk
ON Shops.Sid = shsk.Sid
LEFT OUTER JOIN Skateboards sk
ON shsk.Sk8Id = sk.Sk8Id
WHERE Shoes.Size > 42 AND sk.Size > 7;

/*shops in the city with id 1
 many to many 2
 where 4
 6 tabele 5*/
SELECT Shops.Name AS Shop,Shoes.Name AS Shoes,sk.Name AS Skateboards
FROM Shoes
INNER  JOIN ShopsShoes shsh
ON Shoes.ShoesId = shsh.ShoesId
INNER  JOIN Shops
ON shsh.Sid = Shops.Sid
INNEr  JOIN ShopsSkates shsk
ON Shops.Sid = shsk.Sid
INNER  JOIN Skateboards sk
ON shsk.Sk8Id = sk.Sk8Id
WHERE Shops.Cid = 1;

--managers from romania having an experience of more than 1 year
--group by 1
--having 1
--3 tables 6
SELECT m.Experience
FROM Managers m
LEFT OUTER JOIN Shops s
ON s.Sid = m.Mid
LEFT OUTER JOIN Cities c
ON s.Cid = c.Cid
GROUP BY m.Experience,c.Country
HAVING m.Experience > 1 AND c.Country = 'Romania';

--sites where to find sk8 cheaper than 250
--group by 2
--having 2
--3 tabele 7
SELECT si.Address
FROM Sites si
LEFT OUTER JOIN Shops s
ON si.SiteId = s.Sid
LEFT OUTER JOIN ShopsSkates ss
ON ss.Sid = s.Sid
LEFT OUTER JOIN Skateboards sk
ON ss.Sk8Id = sk.Sk8Id
GROUP BY si.Address,sk.Price
HAVING sk.Price < 250;

--sk8 having sum of components < 150
--group by 3
--distinct 2
--having
--componentele unui sk8 pret<...
SELECT DISTINCT c.Sk8Id,SUM(c.Price) AS Total_price
FROM Components c
GROUP BY c.Sk8Id
HAVING SUM(c.Price) < 150;

--how many shops has a city
SELECT c.Name, COUNT(s.Sid) AS No_Shops
FROM Cities AS c
INNER JOIN Shops s
ON s.Cid = c.Cid
GROUP BY c.Name
ORDER BY c.Name;
