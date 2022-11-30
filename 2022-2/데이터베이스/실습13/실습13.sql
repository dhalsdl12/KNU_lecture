use academicDB;

drop table if exists testTBL;

create table testTBL(
	id		int,
    txt		varchar(20)
);

insert into testTBL values(1, '이멕스아이디');
insert into testTBL values(2, '애프터스쿨');
insert into testTBL values(3, '에이오에이');

drop trigger if exists testTrg;

delimiter //
create trigger testTrg
	after delete
    on testTBL
    for each row
begin
	set @msg = '가수 그룹이 삭제됨';
end //
delimiter ;

set sql_safe_updates=0;
set @msg = ' ';
insert into testTBL values(4, '나인뮤지스');
select @msg;

update testTBL set txt = '에이핑크' where id = 3;
select @msg;

delete from testTBL where id = 4;
select @msg;
select * from testTBL;

select * from student;

delete from enroll;
delete from teach;
delete from student;

select * from student;

use sys;
use academicDB;
select * from student;