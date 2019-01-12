#pragma once
#include<string>
using namespace std;

typedef struct paper{
	//学术硕士论文
	string name;	//论文名字
	int level;		//论文等级(1,2,3)
	double score;		//论文成绩
};

typedef struct project {
	//工程硕士项目
	string name;	//项目名字
	char level;		//项目等级(A,B,C)
	double score;		//项目成绩
};

class Graduate {
	//研究生基类
private:
	string num;		//学号
	string name;	//姓名
	char sex;		//性别
	int age;		//年龄
	double score;		//课程成绩
};


class Graduate_a:public Graduate
{
public:
	static float SumScoreOf_Graduate_a;
	static int numOf_Graduate;
	Graduate_a *pnext;
	Graduate_a();
	double compute_score();
	istream& operator>>(istream &input, Graduate_a &a);
	void saveAcademicStudentData(Graduate_a *head);
private:
	string major;	//专业
	paper p[3];		//论文
	double tscore;	//总成绩
	int pnum;		//论文篇数
};


class Graduate_e :public Graduate
{
	//工程硕士
public:
	Graduate_e *pnext;
	Graduate_e();
	double compute_score();
	istream& operator>>(istream &input, Graduate_e &e);
	void saveEngineerStudentData(Graduate_e *head);

private:
	string area;	//领域
	project p[3];	//项目
	double tscore;	//总成绩
	int pnum;		//项目数
};
