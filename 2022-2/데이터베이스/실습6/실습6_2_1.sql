create database KOM_6;
use KOM_6;

CREATE TABLE buy(
	num			int,
	userID		char(8),
    prodName	varchar(10),
    groupName	varchar(8),
    price		int,
    amount 		int
);
INSERT INTO buy VALUES(1, 'KBS', '운동화', NULL, 30, 2);
INSERT INTO buy VALUES(2, 'KBS', '노트북', '전자', 1000, 1);
INSERT INTO buy VALUES(3, 'JYP', '모니터', '전자', 200, 1);
INSERT INTO buy VALUES(4, 'BBK', '모니터', '전자', 200, 5);
INSERT INTO buy VALUES(5, 'KBS', '청바지', '의류', 50, 3);
INSERT INTO buy VALUES(6, 'BBK', '메모리', '전자', 80, 10);
INSERT INTO buy VALUES(7, 'SSK', '책', '서적', 15, 5);
INSERT INTO buy VALUES(8, 'EJW', '책', '서적', 15, 2);
INSERT INTO buy VALUES(9, 'EJW', '청바지', '의류', 50, 1);
INSERT INTO buy VALUES(10, 'BBK', '운동화', NULL, 30, 2);
INSERT INTO buy VALUES(11, 'EJW', '책', '서적', 15, 1);
INSERT INTO buy VALUES(12, 'BBK', '운동화', NULL, 30, 2);

select * from buy;