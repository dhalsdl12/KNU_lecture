//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[20];
	int mid;
	int final;
	int hw1;
	int hw2;
	int attendance;
}STUDENT;

typedef struct {
	STUDENT student;
	double mid;
	double final;
	double hw;
	double sum;
	char grade[5];
}STUDENT_SCORE;

double MID(STUDENT stu)
{
	return stu.mid * 0.3;
}
double FINAL(STUDENT stu)
{
	return stu.final * 0.4;
}
double HW(STUDENT stu)
{
	return (stu.hw1 + stu.hw2) / (double)2;
}
double SUM(STUDENT_SCORE *a)
{
	return a->mid + a->final + a->hw + a->student.attendance;
}
void GRADE(STUDENT_SCORE* a)
{
	double sum = a->sum;
	
	if (sum >= 95)
		strcpy(a->grade, "A+");
	else if (sum >= 90)
		strcpy(a->grade, "A0");
	else if (sum >= 85)
		strcpy(a->grade, "B+");
	else if (sum >= 80)
		strcpy(a->grade, "B0");
	else if (sum >= 75)
		strcpy(a->grade, "C+");
	else if (sum >= 70)
		strcpy(a->grade, "C0");
	else if (sum >= 65)
		strcpy(a->grade, "D+");
	else if (sum >= 60)
		strcpy(a->grade, "D0");
	else
		strcpy(a->grade, "F");
}
void print(STUDENT_SCORE* a)
{
	printf("학생 정보\n");
	printf(" 학번    이름    중간  기말  과제1 과제2 출석\n");
	printf("---------------------------------------------------\n");
	for(int i = 0; i < 5; i++)
		printf("%d %s%6d%6d%6d%6d%6d\n",
			a[i].student.id, a[i].student.name, a[i].student.mid,
			a[i].student.final, a[i].student.hw1, a[i].student.hw2,
			a[i].student.attendance);
	printf("---------------------------------------------------\n");
	printf("\n");
	printf("성적 정보\n");
	printf(" 학번    이름    중간  기말  과제  출석  총점  학점\n");
	printf("---------------------------------------------------\n");
	for (int i = 0; i < 5; i++)
		printf("%d %s%6.1lf%6.1lf%6.1lf%6d%6.1lf%6s\n",
			a[i].student.id, a[i].student.name, a[i].mid,
			a[i].final, a[i].hw, a[i].student.attendance,
			a[i].sum, a[i].grade);
	printf("---------------------------------------------------\n");
}
int main()
{
	STUDENT student[5] = { {2020019, "홍길동", 10, 20, 0, 5, 10},
			{2021012, "김유신", 35, 55, 27, 15, 7},
			{2019001, "강감찬", 70, 80, 29, 22, 8},
			{2018015, "아무개", 100, 90, 28, 29, 5},
			{2017075, "홍길순", 56, 90, 15, 30, 10} 
	};
	STUDENT_SCORE Grade[5];
	for (int i = 0; i < 5; i++)
	{
		Grade[i].student = student[i];
		Grade[i].mid = MID(student[i]);
		Grade[i].final = FINAL(student[i]);
		Grade[i].hw = HW(student[i]);
		Grade[i].sum = SUM(&Grade[i]);
		GRADE(&Grade[i]);
	}
	print(Grade);
	
	return 0;
}