# db 교재 255p
use academicDB;
drop procedure IF EXISTS studentProc;
delimiter $$
	create procedure studentProc()
    begin
		select * from student;
	end $$
delimiter ;
call studentProc();

# db 교재 257p
use academicDB;
drop procedure IF EXISTS studentProc1;
delimiter $$
	create procedure studentProc1(in userName varchar(10))
    begin
		select * from student where sname = userName;
	end $$
delimiter ;
call studentProc1('김철수');

# db 교재 258p
drop procedure IF EXISTS studentProc2;
delimiter $$
	create procedure studentProc2
		(in userName varchar(10), in deptName varchar(20))
    begin
		select * from student 
			where sname = userName and sdept = deptName;
	end $$
delimiter ;
call studentProc2('김철수', '컴퓨터');

# db 교재 259p
drop procedure if exists testProc;
delimiter $$
	create procedure testProc(in txtValue varchar(10), out outValue int )
    begin
		insert into testTBL values(null, txtValue);
        select max(id) into outValue from testTBL;
	end $$
delimiter ;

create table if not exists testTBL (
	id 		int 		auto_increment primary key,
    txt		char(10)
);

# db 교재 260p
call testProc('테스트값', @myValue);
select concat('현재 입력된 ID값 ==>', @myValue);


#db 교재 261p
drop procedure if exists ifelseProc;
delimiter $$
	create procedure ifelsePorc(in number int)
    begin
		declare eScore int;
        select score into eScore from enroll where sno = number;
        if(eScore >= 90) then select 'A 학점';
        else select 'B 학점';
        end if;
	end $$
delimiter ;

call ifelsePorc(20183654);

# db 교재 262p
drop procedure if exists cursorProc;
delimiter $$
	create procedure cursorProc()
    begin
		declare eScore int;
        declare count int default 0;
        declare total int default 0;
        declare endOfRow boolean default FALSE;
        
        declare cur CURSOR FOR select score from enroll;
        declare continue handler for not found set
			endOfRow = True;
		open cur;
        
        cursor_loop: LOOP
			fetch cur into eScore;
            if endOfRow then
				leave cursor_loop;
			end if;
            set count = count + 1;
            set total = total + eScore;
		end loop cursor_loop;
        
        select concat('수강생 평균 점수 ==> ', (total/count));
        close cur;
	end $$
delimiter ;

call cursorProc();