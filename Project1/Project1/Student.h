#pragma once
#include<string>
#include<string.h>
using namespace std;
class Graduate {
private:
	string uid;
	string name;
	bool sex;
	int age;
	int score;
};
class Gradute_a:public Graduate
{
public:
	Gradute_a *pnext;
	Gradute_a();
	~Gradute_a();
	double compute_score();
	istream& operator>>(istream &input, Gradute_a &a);
private:
	string major;
	pair<string, int> papers[3];
	double paper_score;
	double total_score;
};
Gradute_a::Gradute_a()
{
}

Gradute_a::~Gradute_a()
{
}
class Gradute_e :public Graduate
{
public:
	Gradute_e *pnext;
	Gradute_e();
	~Gradute_e();
	double compute_score();
	istream& operator>>(istream &input, Gradute_e &e);
private:
	string field;
	pair<string, char> projects[3];
	double project_score;
	double total_score;
};

Gradute_e::Gradute_e()
{
}

Gradute_e::~Gradute_e()
{
}
