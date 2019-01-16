#include<iostream>
#include<cmath>
#include <stdlib.h>
#include<string>
#include"Student.h"

using namespace std;

//ͳ�ƺ���
void Graduate_a::statisticalData(){
	if (aHead->pnext == NULL)
	{
		cerr << "����0x456121" << endl;
		cerr << "����ϵ����Ա����������������ݣ�" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p = aHead->pnext;
	while (p != NULL)
	{
		countAcademicNumber++;
		sumAcademicScore = (double)(sumAcademicScore + p->tscore);
		if (fabs((float)(p->tscore - 100.0)) < 0.00001)//ע��˵��
		{
			a[0]++;
		}
		else if (p->tscore >= 90.0000 && p->tscore <= 99.0000)
		{
			a[1]++;
		}
		else if (p->tscore >= 80.0000 && p->tscore <= 89.0000)
		{
			a[2]++;
		}
		else if (p->tscore >= 70.0000 && p->tscore <= 79.0000)
		{
			a[3]++;
		}
		else if (p->tscore >= 60.0000 && p->tscore <= 69.0000)
		{
			a[4]++;
		}
		else if (p->tscore < 60.0000)
		{
			a[5]++;
		}
		p = p->pnext;
	}
	averageAcademicScore = (double)((sumAcademicScore)*1.0 / countAcademicNumber);
	//ͳ�����,��ʼ��������Ϣ
	cout << "ѧ��˶ʿ������Ϊ��" << countAcademicNumber << endl;
	cout << "�������ǵ�ƽ����Ϊ��" << averageAcademicScore << endl;
	cout << "�ɼ��ֲ�Ϊ��" << endl;
	cout << "100������Ϊ��" << a[0] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[0] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "90~99������Ϊ��" << a[1] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[1] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "80~89������Ϊ��" << a[2] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[2] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "70~79������Ϊ��" << a[3] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[3] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "60~69������Ϊ��" << a[4] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[4] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "����������Ϊ��" << a[5] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(a[5] * 1.0 / countAcademicNumber) << "%" << endl;
	return;
}

void Graduate_e::statisticalData() {
	if (eHead->pnext == NULL)
	{
		cerr << "����0x456121" << endl;
		cerr << "����ϵ����Ա����������������ݣ�" << endl;
		system("pause");
		exit(0);
	}
	Graduate_e *p = eHead->pnext;
	while (p != NULL)
	{
		countEngineeringNumber++;
		sumEngineeringScore = (double)(sumEngineeringScore + p->tscore);
		if (fabs((float)(p->tscore - 100.0)) < 0.00001)//ע��˵��
		{
			e[0]++;
		}
		else if (p->tscore >= 90.0000 && p->tscore <= 99.9999)
		{
			e[1]++;
		}
		else if (p->tscore >= 80.0000 && p->tscore <= 89.9999)
		{
			e[2]++;
		}
		else if (p->tscore >= 70.0000 && p->tscore <= 79.9999)
		{
			e[3]++;
		}
		else if (p->tscore >= 60.0000 && p->tscore <= 69.9999)
		{
			e[4]++;
		}
		else if (p->tscore < 60.0000)
		{
			e[5]++;
		}
		p = p->pnext;
	}
	averageEngineeringScore = (double)((sumEngineeringScore)*1.0 / countEngineeringNumber);
	//ͳ�����,��ʼ��������Ϣ
	cout << "����˶ʿ������Ϊ��" << countEngineeringNumber << endl;
	cout << "�������ǵ�ƽ����Ϊ��" << averageEngineeringScore << endl;
	cout << "�ɼ��ֲ�Ϊ��" << endl;
	cout << "100������Ϊ��" <<e[0] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[0] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "90~99������Ϊ��" << e[1] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[1] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "80~89������Ϊ��" << e[2] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[2] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "70~79������Ϊ��" << e[3] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[3] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "60~69������Ϊ��" << e[4] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[4] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "����������Ϊ��" << e[5] << "\tռ�������ٷֱ�Ϊ��" << 100 * (double)(e[5] * 1.0 / countEngineeringNumber) << "%" << endl;
	return;
}

void Graduate_a::Bsort(int i) {
	int min=0;
	if (aHead->pnext == NULL){
		cerr << "����0x456121" << endl;
		cerr << "����ϵ����Ա����������������ݣ�" << endl;
		system("pause");
		exit(0);
	}
	
	//=============ð������====================
	Graduate_a *head_1 = aHead;
	Graduate_a *pre, *cur, *next, *end, *temp;
	end = NULL;
	
	switch (i) {
	case 1:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->tscore < next->tscore) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
		break;
	case 2:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->getNum()>next->getNum()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	case 3:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->getName()>next->getName()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	}
}



void Graduate_e::Bsort(int i) {
	int min = 0;
	if (eHead->pnext == NULL) {
		cerr << "����0x456121" << endl;
		cerr << "����ϵ����Ա����������������ݣ�" << endl;
		system("pause");
		exit(0);
	}

	//=============ð������====================
	Graduate_e *head_1 = eHead;
	Graduate_e *pre, *cur, *next, *end, *temp;
	end = NULL;

	switch (i) {
	case 1:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->getTscore() < next->getTscore()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
		break;
	case 2:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->getNum() > next->getNum()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	case 3:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//���ڵĽڵ�Ƚ�
				if (cur->getName() > next->getName()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	}
	
}
