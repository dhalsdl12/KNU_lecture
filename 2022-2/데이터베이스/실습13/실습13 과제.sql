use academicdb;

insert into student values(12345678, "김철수", "수학", "010-1234-5678");

drop table if exists backup_student;
create table backup_student(
	sno 		int,
	sname 		char(5) not null,
	sdept 		char(20),
	stel 		char(20),
	modType 	char(2), -- 변경된 타입, 수정 또는 삭제
	modDate 	date, -- 변경된 날짜
	modUser 	varchar(50) -- 변경한 사용자
);

drop trigger IF EXISTS UpdateTrg;
DELIMITER //
create trigger UpdateTrg
	after update
    on	 student
	for each row
BEGIN
	insert into backup_student values (OLD.sno, OLD.sname, OLD.sdept,
	OLD.stel, '수정', CURDATE(), CURRENT_USER() );
 END //
DELIMITER ;

drop trigger IF EXISTS DeleteTrg;
DELIMITER //
create trigger DeleteTrg
   after delete
    on student
    for each row
 BEGIN
	insert into backup_student values (OLD.sno, OLD.sname, OLD.sdept,
	OLD.stel, '삭제', CURDATE(), CURRENT_USER() );
 END //
DELIMITER ;

UPDATE student SET sname= '홍길동'  WHERE sno = 12345678;
delete from student where sno=12345678;

select * from backup_student;