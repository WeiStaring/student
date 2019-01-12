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
public:
	string getNum()const { return num; }//获取学号
	string getName()const { return name; }//获取姓名
protected:
	string num;		//学号
	string name;	//姓名
	char sex;		//性别
	int age;		//年龄
	double score;		//课程成绩
};


class Graduate_a:public Graduate
{
public:
	Graduate_a *pnext;
	Graduate_a() {
	}

	void saveAcademicStudentData(Graduate_a *head);

	double calculatePaperScore();//计算论文分数
	double calculateSumScore();//计算总成绩

	//重载函数
	friend ostream& operator<<(ostream&, Graduate_a&);
	friend istream& operator>>(istream&, Graduate_a&);

	//统计函数
	static void statisticalData(Graduate_a*);
	static float sumAcademicScore;						//学术硕士全体总成绩
	static int countAcademicNumber;						//学术硕士总人数
	static float averageAcademicScore;					//学术硕士平均成绩
	static int a[6];									//学术硕士总分分段人数


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

	void saveAcademicStudentData(Graduate_a *head);

	double calculateEngineerScore();//计算项目分数
	double calculateSumScore();//计算总成绩

	//重载函数
	friend ostream& operator<<(ostream&, Graduate_e&);
	friend istream& operator>>(istream&, Graduate_e&);
	//统计函数
	static void statisticalData(Graduate_e*);
	static double sumEngineeringScore;//工程硕士全体总成绩
	static int countEngineeringNumber;//工程硕士总人数
	static double averageEngineeringScore;//工程硕士平均成绩
	static int e[6];//学术硕士总分分段人数

private:
	string area;	//领域
	project p[3];	//项目
	double tscore;	//总成绩
	int pnum;		//项目数
};

