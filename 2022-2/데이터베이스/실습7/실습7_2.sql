create database kom_7;

use kom_7;

create table professor(
	pno 	char(10),
    pname 	char(5),
    pdept 	char(20),
    ptel 	char(20),
    primary key(pno)
);
insert into professor values('P200','홍길동','컴퓨터','010-0865-7632');
insert into professor values('P202','박영순','전자','010-8641-0541');
insert into professor values('P203','김기준','기계','010-7812-0432');
insert into professor values('P204','김형일','화학','010-8432-1653');
insert into professor values('P205','강선화','컴퓨터','010-5846-4765');
insert into professor values('P206','정인수','전자','010-8536-4587');


CREATE TABLE student
( 
	sno 	int,
    sname 	char(5),
    sdept 	char(20),
    stel 	char(20),
    primary key(sno)
);
INSERT INTO student VALUES(20181234,'김철수','컴퓨터','010-4657-7654');
INSERT INTO student VALUES(20182587,'이영자','컴퓨터','010-7654-9874');
INSERT INTO student VALUES(20183654,'고영준','경영','010-8732-0953');
INSERT INTO student VALUES(20184652,'김영옥','전자','010-7623-8753');
INSERT INTO student VALUES(20185753,'유진호','기계','010-5431-0964');
INSERT INTO student VALUES(20187654,'박용철','컴퓨터','010-6548-9872');


create table course (
	code 	char(5),
	cname 	char(20),
	credit 	smallint,
	year 	smallint,
	primary key(code)
);
insert into course values('CO123','데이터베이스',3,3);      
insert into course values('CO234','네트워크',3,2);
insert into course values('CO342','그래픽응용',2,3);
insert into course values('CO423','프로그래밍',3,4);
insert into course values('EE123','신호처리',3,2);
insert into course values('ME102','열역학',3,3);


create table teach(
	pno 	char(10),
    sno 	int,
	foreign key(pno) references professor(pno),
    foreign key(sno) references student(sno)
);
insert into teach values('P200','20181234');
insert into teach values('P200','20182587');
insert into teach values('P200','20185753');
insert into teach values('P202','20183654');
insert into teach values('P202','20184652');
insert into teach values('P203','20187654');


create table lecture(
	pno 	char(10),
    code 	char(5),
    hour 	smallint,
    room 	char(5),
	foreign key(pno) references professor(pno),
    foreign key(code) references course(code)
);
insert into lecture values('P200','CO123',3,'E453');    
insert into lecture values('P200','CO423',3,'E265');      
insert into lecture values('P202','CO234',3,'K458');      
insert into lecture values('P202','CO342',4,'E234');      
insert into lecture values('P202','EE123',4,'K124');      
insert into lecture values('P203','ME102',3,'E234');     


create table enroll(
	sno		 int,
	code 	char(5),
    score 	int,
    grade 	char(2),
	foreign key(sno) references student(sno),
    foreign key(code) references course(code)
);
insert into enroll values(20181234,'CO123',94,'A0');
insert into enroll values(20181234,'CO423',87,'B+');
insert into enroll values(20182587,'CO123',91,'A-');
insert into enroll values(20182587,'CO423',86,'B+');
insert into enroll values(20182587,'EE123',74,'C0');
insert into enroll values(20183654,'CO234',97,'A+');
insert into enroll values(20184652,'CO123',83,'B0');
insert into enroll values(20184652,'CO234',81,'B-');
insert into enroll values(20184652,'CO423',64,'D0');
insert into enroll values(20184652,'EE123',89,'B+');
insert into enroll values(20185753,'CO423',85,'B0');

select * from course;
select * from professor;
select * from student;

select * from enroll;
select * from teach;
select * from lecture;