drop database if exists academicDB; 
create database academicDB;
use academicDB;
create table student (
	sno int,
 	sname char(5) not null,
 	sdept char(20),
    stel char(20),
 	primary key(sno)
	);
create table professor (
	pno char(4) not null,
    pname char(5) not null,
    pdept char(20),
    ptel char(20),
    primary key(pno)
	);
create table course (
	code char(5) not null,
 	cname char(20) not null,
 	credit smallint,
 	year smallint,
 	primary key(code)
	);
create table lecture (
	pno char(4) not null,
    code char(5) not null,
    hour smallint,
    room char(4),
    foreign key(pno) references professor(pno),
    foreign key(code) references course(code)
	);
create table teach (
	pno char(4) not null,
    sno int not null,
    foreign key(pno) references professor(pno),
    foreign key(sno) references student(sno)
	);
 create table enroll (
	sno  int not null,
 	code char(5) not null,
    score smallint,
 	grade char(2),
 	foreign key(sno) references student(sno),
 	foreign key(code) references course(code)
    );

insert into student values(20181234, '김철수', '컴퓨터', '010-4657-7654'); 
insert into student values(20182587, '이영자', '컴퓨터', '010-7654-9874'); 
insert into student values(20183654, '고영준', '경영', '010-8732-0953'); 
insert into student values(20184652, '김영옥', '전자', '010-7623-8753'); 
insert into student values(20185753, '유진호', '기계', '010-5431-0964'); 
insert into student values(20187654, '박용철', '컴퓨터', '010-6548-9872'); 

insert into professor values('P200', '홍길동', '컴퓨터', '010-0865-7632'); 
insert into professor values('P202', '박영순', '전자', '010-8641-0541'); 
insert into professor values('P203', '김기준', '기계', '010-7812-0432'); 
insert into professor values('P204', '김형일', '화학', '010-8432-1653'); 
insert into professor values('P205', '강선화', '컴퓨터', '010-5846-4765'); 
insert into professor values('P206', '정인수', '전자', '010-8536-4587'); 

insert into course values('CO123', '데이터베이스', 3, 3);
insert into course values('CO234', '네트워크', 3, 2);
insert into course values('CO342', '그래픽응용', 2, 3);
insert into course values('CO423', '프로그래밍', 3, 4);
insert into course values('EE123', '신호처리', 3, 2);
insert into course values('ME102', '열역학', 3, 3);

insert into lecture values('P200', 'CO123', 3, 'E453');
insert into lecture values('P200', 'CO423', 3, 'E265');
insert into lecture values('P202', 'CO234', 3, 'K458');
insert into lecture values('P202', 'CO342', 4, 'E234');
insert into lecture values('P202', 'EE123', 4, 'K124');
insert into lecture values('P203', 'ME102', 3, 'E324');

insert into teach values('P200', 20181234);
insert into teach values('P200', 20182587);
insert into teach values('P200', 20185753);
insert into teach values('P202', 20183654);
insert into teach values('P202', 20184652);
insert into teach values('P203', 20187654);

insert into enroll values(20181234, 'CO123', 94, 'A0');
insert into enroll values(20181234, 'CO423', 87, 'B+');
insert into enroll values(20182587, 'CO123', 91, 'A-');
insert into enroll values(20182587, 'CO423', 86, 'B+');
insert into enroll values(20182587, 'EE123', 74, 'C0');
insert into enroll values(20183654, 'CO234', 97, 'A+');
insert into enroll values(20184652, 'CO123', 83, 'B0');
insert into enroll values(20184652, 'CO234', 81, 'B-');
insert into enroll values(20184652, 'CO423', 64, 'D0');
insert into enroll values(20184652, 'EE123', 89, 'B+');
insert into enroll values(20185753, 'CO423', 85, 'B0');

create index idx_student_sname on student(sname);
create index idx_professor_pname on professor(pname);
create index idx_course_cname on course(cname);

select * from student;
select * from professor;
select * from course;
select * from lecture;
select * from teach;
select * from enroll;

# 1
select * from student;
# 2
select distinct sdept from student;
# 3
select cname from course where credit=3 and year=4;
# 4
select code, cname from course where code like 'CO%';
# 5
select pno, code from lecture where room is null;
# 6
select * from enroll where score between 80 and 90;
# 7
select sno, grade from enroll where score >= 80 order by sno asc, grade desc;
# 8 
select sno as DS수강학번, "최종점수 = " as 내용, score + 2 as 수정점수 from enroll where code='CO123';
# 9
select sname, sdept, score from student inner join enroll where code='CO423' and student.sno=enroll.sno;
# 10
select s1.sno, s2.sno from student s1, student s2 where s1.sdept=s2.sdept order by s1.sno asc;
# 11
select count(*) as 학생수 from student;
# 12
select avg(score) as 평균 from enroll where code='CO123';
# 13
select code, avg(score) as 평균 from enroll group by code;
# 14
select code, avg(score) as 평균 from enroll group by code having count(*) >= 2;
# 15
select sname from student where sdept in (select sdept from student where sname='김철수');
# 16
select sname from student where sno in (select sno from enroll where code='CO123');
# 17
select sname from student where sno not in (select sno from enroll where code='CO123');
# 18
select sname from student where exists (select * from enroll where enroll.sno=student.sno and code='CO123');
# 19
select sno from student where sdept='컴퓨터' UNION select sno from enroll where code='EE123';
 

   
