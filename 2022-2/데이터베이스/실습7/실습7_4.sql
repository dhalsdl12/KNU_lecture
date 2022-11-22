use kom_7;

drop table if exists orders;
drop table if exists customer;
create table customer(
	customerID	char(4)			not null primary key,
    name		varchar(10)		not null,
	addr		char(2)			not null,
    mobile		char(13)		null
);
insert into customer values('C100','이만수','서울','011-1111-1111');
insert into customer values('C200','김일범','경남','011-2222-2222');
insert into customer values('C300','김경자','전남','019-3333-3333');
insert into customer values('C400','조영희','경기','011-4444-4444');
insert into customer values('C500','백태영','서울','011-5555-5555');
insert into customer values('C600','윤종찬','전남',null);

create table orders(
	num			int		not null auto_increment primary key,
    item		char(10),
    money		int,
    count		int,
    customerID 	char(4),
    foreign key(customerID) references customer(customerID)
);
insert into orders(item, money, count, customerID) values('운동화',30, 2, 'C200');
insert into orders(item, money, count, customerID) values('노트북',1000, 1, 'C200');
insert into orders(item, money, count, customerID) values('전화기',200, 1, 'C400');
insert into orders(item, money, count, customerID) values('가방',300, 1, 'C500');

select * from customer;
select * from orders;
show index from orders;

drop table if exists orders;
drop table if exists customer;
create table customer(
	customerID	char(4)			not null primary key,
    name		varchar(10)		not null unique,
	addr		char(2)			default "서울",
    mobile		char(13)		null,
    constraint	CK_addr			check (addr is not null)
);
insert into customer values('C100','이만수','서울','011-1111-1111');
insert into customer values('C200','김일범','경남','011-2222-2222');
insert into customer values('C300','김경자','전남','019-3333-3333');
insert into customer values('C400','조영희','경기','011-4444-4444');
insert into customer values('C500','백태영',default,'011-5555-5555');
insert into customer values('C600','윤종찬','전남',null);

create table orders(
	num			int		not null auto_increment primary key,
    item		char(10),
    money		int,
    count		int,
    customerID 	char(4),
    foreign key(customerID) references customer(customerID),
    constraint	CK_count			check (count > 0)
);
insert into orders(item, money, count, customerID) values('운동화',30, 2, 'C200');
insert into orders(item, money, count, customerID) values('노트북',1000, 1, 'C200');
insert into orders(item, money, count, customerID) values('전화기',200, 1, 'C400');
insert into orders(item, money, count, customerID) values('가방',300, 1, 'C500');

select * from orders;
select * from customer;