#include<iostream>
#include"menu.h"
#include"Student.h"
using namespace std;

double Graduate_a::sumAcademicScore = 0; // ѧ��˶ʿȫ���ܳɼ�
int Graduate_a::countAcademicNumber = 0;//ѧ��˶ʿ������
double Graduate_a::averageAcademicScore = 0;//ѧ��˶ʿƽ���ɼ�
int Graduate_a::a[6] = { 0,0,0,0,0,0 };//ѧ��˶ʿ�ֶַܷ�����

double Graduate_e::sumEngineeringScore = 0;//����˶ʿȫ���ܳɼ�
int Graduate_e::countEngineeringNumber = 0;//����˶ʿ������
double Graduate_e::averageEngineeringScore = 0;//����˶ʿƽ���ɼ�
int Graduate_e::e[6] = { 0,0,0,0,0,0 };//ѧ��˶ʿ�ֶַܷ�����

Graduate_a *Graduate_a::aHead = new Graduate_a();  //Graduate_a������ͷ��㣬ͷ������һ��Ϊ��һ����¼
Graduate_e *Graduate_e::eHead = new Graduate_e();  //Graduate_e������ͷ��㣬ͷ������һ��Ϊ��һ����¼

int main()
{
	//welcome();
	menu();


	system("pause");
	return 0;
}
