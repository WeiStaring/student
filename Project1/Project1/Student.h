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
	Gradute_a();
	~Gradute_a();
	double compute_score() {

	}
private:
	string major;
	pair<string, int> papers[3];
	int paper_score;
	int total_score;
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
	Gradute_e();
	~Gradute_e();
	double compute_score() {

	}
private:
	string field;
	pair<string, char> projects[3];
	int project_score;
	int total_score;
};

Gradute_e::Gradute_e()
{
}

Gradute_e::~Gradute_e()
{
}
