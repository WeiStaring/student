#include<iostream>
#include"Student.h"
using namespace std;

float Graduate_a::SumScoreOf_Graduate_a = 0.0;
int Graduate_a::numOf_Graduate = 0;
float avrScoreOf_Graduate_a = 0.0;
int a[6] = { 0,0,0,0,0,0 };
//ͳ�ƺ���
void Graduate_a::statisticalData(academicGraduateStudent *head){
	if (head->paNext == NULL)
	{
		cerr << "����0x456121" << endl;
		cerr << "����ϵ����Ա����������������ݣ�" << endl;
		system("pause");
		exit(0);
	}
	academicGraduateStudent *p = head->paNext;
	while (p != NULL)
	{
		countAcademicNumber++;
		sumAcademicScore = (float)(sumAcademicScore + p->sumScore);
		if (fabs(p->sumScore - 100) < 0.00001)//ע��˵��
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
	//ͳ�����,��ʼ��������Ϣ
	cout << "ѧ��˶ʿ������Ϊ��" << countAcademicNumber << endl;
	cout << "�������ǵ�ƽ����Ϊ��" << averageAcademicScore << endl;
	cout << "�ɼ��ֲ�Ϊ��" << endl;
	cout << "100����Ϊ��" << a[0] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[0] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "90~99����Ϊ��" << a[1] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[1] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "80~89����Ϊ��" << a[2] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[2] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "70~79����Ϊ��" << a[3] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[3] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "60~69����Ϊ��" << a[4] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[4] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "����������Ϊ��" << a[5] << "ռ�������ٷֱ�Ϊ��" << 100 * (float)(a[5] * 1.0 / countAcademicNumber) << "%" << endl;
	return;
}
