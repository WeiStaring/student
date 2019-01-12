#include<iostream>
#include"Student.h"
using namespace std;

float Graduate_a::SumScoreOf_Graduate_a = 0.0;
int Graduate_a::numOf_Graduate = 0;
float avrScoreOf_Graduate_a = 0.0;
int a[6] = { 0,0,0,0,0,0 };
//统计函数
void Graduate_a::statisticalData(academicGraduateStudent *head){
	if (head->paNext == NULL)
	{
		cerr << "错误0x456121" << endl;
		cerr << "请联系管理员解决（链表中无数据）" << endl;
		system("pause");
		exit(0);
	}
	academicGraduateStudent *p = head->paNext;
	while (p != NULL)
	{
		countAcademicNumber++;
		sumAcademicScore = (float)(sumAcademicScore + p->sumScore);
		if (fabs(p->sumScore - 100) < 0.00001)//注意说明
		{
			a[0]++;
		}
		else if (p->sumScore >= 90.0000 && p->sumScore <= 99.0000)
		{
			a[1]++;
		}
		else if (p->sumScore >= 80.0000 && p->sumScore <= 89.0000)
		{
			a[2]++;
		}
		else if (p->sumScore >= 70.0000 && p->sumScore <= 79.0000)
		{
			a[3]++;
		}
		else if (p->sumScore >= 60.0000 && p->sumScore <= 69.0000)
		{
			a[4]++;
		}
		else if (p->sumScore < 60.0000)
		{
			a[5]++;
		}
		p = p->paNext;
	}
	averageAcademicScore = (float)((sumAcademicScore)*1.0 / countAcademicNumber);
	//统计完毕,开始输出相关信息
	cout << "学术硕士总人数为：" << countAcademicNumber << endl;
	cout << "其中他们的平均分为：" << averageAcademicScore << endl;
	cout << "成绩分布为：" << endl;
	cout << "100人数为：" << a[0] << "占总人数百分比为：" << 100 * (float)(a[0] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "90~99人数为：" << a[1] << "占总人数百分比为：" << 100 * (float)(a[1] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "80~89人数为：" << a[2] << "占总人数百分比为：" << 100 * (float)(a[2] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "70~79人数为：" << a[3] << "占总人数百分比为：" << 100 * (float)(a[3] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "60~69人数为：" << a[4] << "占总人数百分比为：" << 100 * (float)(a[4] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "不及格人数为：" << a[5] << "占总人数百分比为：" << 100 * (float)(a[5] * 1.0 / countAcademicNumber) << "%" << endl;
	return;
}
