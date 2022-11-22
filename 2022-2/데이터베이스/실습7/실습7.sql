create database report;

use report;

drop table if exists ApartPrice;
create table ApartPrice(
	no 			int 		not null primary key,
    ymd 		date,
    ym 			date,
    year 		char(4),
    code 		char(5),
    addr1 		char(10),
    apt_nm 		varchar(50),
    juso_jibun 	varchar(200),
    price 		decimal(10),
    con_year 	decimal(4)	default "2022",
    area 		decimal(5),
    floor 		decimal(3),
    py 			decimal(5),
    cnt 		decimal(3),
    constraint	CK_cnt		check (0 < cnt < 100)
);
load data infile "C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Uploads\\final_csv_data.csv"
into table ApartPrice
FIELDS TERMINATED BY ',' 
ENCLOSED BY ' '
LINES TERMINATED BY '\n'
IGNORE 1 ROWS
(no, ymd, ym, year, code, addr1, apt_nm, juso_jibun, @checks, con_year, area, floor, @pycheck, cnt)
SET price = case when @checks = 'NA' then null else @checks end,
	py = case when @pycheck = 'NA' then null else @pycheck end;

select * from ApartPrice;