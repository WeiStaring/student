#include<iostream>
#include"menu.h"
#include"Student.h"
using namespace std;

double Graduate_a::sumAcademicScore = 0; // 学术硕士全体总成绩
int Graduate_a::countAcademicNumber = 0;//学术硕士总人数
double Graduate_a::averageAcademicScore = 0;//学术硕士平均成绩
int Graduate_a::a[6] = { 0,0,0,0,0,0 };//学术硕士总分分段人数

double Graduate_e::sumEngineeringScore = 0;//工程硕士全体总成绩
int Graduate_e::countEngineeringNumber = 0;//工程硕士总人数
double Graduate_e::averageEngineeringScore = 0;//工程硕士平均成绩
int Graduate_e::e[6] = { 0,0,0,0,0,0 };//学术硕士总分分段人数

Graduate_a *Graduate_a::aHead = new Graduate_a();  //Graduate_a的链表头结点，头结点的下一个为第一个记录
Graduate_e *Graduate_e::eHead = new Graduate_e();  //Graduate_e的链表头结点，头结点的下一个为第一个记录

int main()
{
	//welcome();
	menu();


	system("pause");
	return 0;
}
