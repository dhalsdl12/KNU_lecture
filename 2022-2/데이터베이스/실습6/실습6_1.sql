create database KOM_6;
use KOM_6;

CREATE TABLE user(
	userID		char(8),
    name		varchar(10),
    birthYear	int,
    addr		char(2),
    mobile		char(13),
    height		smallint,
    mDate		date
);
INSERT INTO user VALUES('LSG', '이승기', 1987, '서울', '011-1111-111', 182, '2008-8-8');
INSERT INTO user VALUES('KBS', '김범수', 1979, '경남', '011-222-2222', 173, '2012-4-4');
INSERT INTO user VALUES('KKH', '김경호', 1971, '전남', '019-333-3333', 177, '2007-7-7');
INSERT INTO user VALUES('JYP', '조용필', 1950, '경기', '011-444-4444', 166, '2009-4-4');
INSERT INTO user VALUES('SSK', '성시경', 1979, '서울', NULL, 186, '2013-12-12');
INSERT INTO user VALUES('LJB', '임재범', 1963, '서울', '016-666-6666', 182, '2009-9-9');
INSERT INTO user VALUES('YJS', '윤종신', 1969, '경남', NULL, 170, '2005-5-5');
INSERT INTO user VALUES('EJW', '은지원', 1972, '경북', '011-888-8888', 174, '2014-3-3');
INSERT INTO user VALUES('JKW', '조관우', 1965, '경기', '018-999-9999', 172, '2010-10-10');
INSERT INTO user VALUES('BBK', '바비킴', 1973, '서울', '010-000-0000', 176, '2013-5-5');


alter table user add constraint pk_name primary key(userID);

create index idx_user_addr on user(addr);
create unique index idx_user_name on user(name);
create index idx_user_name_mdate on user(name, mdate);

drop index idx_user_addr on user;
drop index idx_user_name on user;
drop index idx_user_name_mdate on user;
alter table user drop primary key;