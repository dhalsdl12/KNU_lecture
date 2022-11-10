use kom_9;
-- 1) 과목 ‘CO123’의 성적이 ‘A0’인 학생의 학번과 성명은?
-- { s.학번, s.성명 | 학생(s) ∧ ∃e(수강(e) ∧ e.학번=s.학번 ∧ e.과목코드=‘CO123’ ∧ e.성적=‘A0’) }
select student.sno, sname from student 	inner join enroll on student.sno=enroll.sno
										where code='CO123' and grade='A0';

-- 2) 모든 과목에 등록한 학생의 성명은?
-- { s.성명 | 학생(s) ∧ ∀c∃e(과목(c) ∧ 수강(e) ∧ c.과목코드=e.과목코드 ∧ s.학번=e.학번) }
select sname from student 	inner join enroll on student.sno=enroll.sno
							inner join course on course.code=enroll.code
							group by student.sno having count(*)=(select count(*) from course);
                            
-- 3) 4학년 과목을 적어도 한 과목 등록한 학생의 성명은?
-- { s.성명 | 학생(s) ∧ ∃c∃e(과목(c) ∧ 수강(e) ∧ s.학번=e.학번 ∧ c.과목코드=e.과목코드 ∧ c.학년=4)}
select sname from student  	inner join enroll on student.sno=enroll.sno
							inner join course on course.code=enroll.code
                            where year=4;

-- 4) 과목 ‘CO234’의 점수가 90점 이상인 학생의 성명과 학과는?
-- { s.성명, s.학과 | 학생(s) ∧ ∃e(수강(e) ∧ s.학번=e.학번 ∧ e.과목코드=‘CO234’ ∧ e.성적>=90) }
select sname, sdept from student 	inner join enroll on student.sno=enroll.sno
									where code='CO234' and score>=90;