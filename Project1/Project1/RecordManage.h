#pragma once
#include<iostream>
#include"Student.h"
using namespace std;


//ѧ�����о�����ͨ�����Ķ���
Graduate_a* seekAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
loop:
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "�����������������룡" << endl;
		goto loop;
	}
	Graduate_a *p = head->pnext;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	loopnu:
		cout << "������ѧ�ţ�" << endl;
		cin >> targetNum;
		while (p->getNum() != targetNum)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopnu;
		}
		return p;
		break;
	case 2:
	loopna:
		cout << "������������" << endl;
		cin >> targetName;
		while (p->getName() != targetName)
		{
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopna;
		}
		return p;
		break;

	default:
		cerr << "������룺0x123459��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
}
Graduate_a* inputAcademicData(Graduate_a *head)//¼��ѧ���о�������
{
	Graduate_a *p, *q;
	p = q = new Graduate_a;
	if (p == NULL || q == NULL)//�����ڴ�ʧ�ܲ���
	{
		cerr << "������룺0x123456��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	cout << "��ʼ¼�����ݣ�ѧ��Ϊ��ʱ������" << endl;
	cin >> *p;
	cout << "¼��ɹ���" << endl;
	int i = 1;

	while (p->getNum() != "")
	{
		if (i == 1)
		{
			head->pnext = p;
		}
		else
		{
			q->pnext = p;
		}
		q = p;
		p = new Graduate_a;
		if (p == NULL)//�����ڴ�ʧ�ܲ���
		{
			cerr << "������룺0x123457��" << endl;
			cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
			system("pause");
			exit(0);
		}
		cin >> *p;
		p->getNum();
		if (p->getNum() != "")
		{
			cout << "¼��ɹ���" << endl;
		}
		else
		{
			cout << "¼�����!" << endl;
		}
		i++;
	}
	q->pnext = NULL;
	return head;
}
Graduate_a* insertAcademicData(Graduate_a *head)//����ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;

	cout << "������һ���µ����ݣ�ѧ���о�����" << endl;
	p = new Graduate_a;
	if (p == NULL)
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	cin >> *p;
	cout << "¼��ɹ���" << endl;
	cout << "������������ĸ�����֮��" << endl;
	//�ҵ�Ҫ�������
	q = seekAcademicData(aHead);
	p->pnext = q->pnext;
	q->pnext = p;
	return head;
}
Graduate_a* delAcademicData(Graduate_a *head)//ɾ��ĳ��ѧ���о�������
{
	if (head->pnext == NULL)//�жϻ������Ƿ�������
	{
		cerr << "������룺0x123458��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p, *q;
loop:
	cout << "ѧ�ţ�1���� ������2����" << endl;
	int i = 0;
	cin >> i;
	if (!(i == 1 || i == 2))
	{
		cerr << "�����������������룡" << endl;
		goto loop;
	}
	p = head->pnext;
	q = head;
	string targetNum;
	string targetName;
	switch (i)
	{
	case 1:
	loopnu:
		cout << "������ѧ�ţ�" << endl;
		cin >> targetNum;
		while (p->getNum() != targetNum)
		{
			q = p;
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopnu;
		}
		break;
	case 2:
	loopna:
		cout << "������������" << endl;
		cin >> targetName;
		while (p->getName() != targetName)
		{
			q = p;
			p = p->pnext;
		}
		if (p == NULL)
		{
			cerr << "û��������ݣ����������룡" << endl;
			goto loopna;
		}
		break;

	default:
		cerr << "������룺0x123459��" << endl;
		cerr << "�쳣���󣡣����ϱ�����Ա����" << endl;
		system("pause");
		exit(0);
	}
	i = 0;
loopq:
	cout << "�Ƿ�ȷ��ɾ�����ǣ�1���� ��2��" << endl;
	cin >> i;
	if (i == 1)
	{
		q->pnext = p->pnext;
	}
	else if (i == 2)
	{
		cerr << "ȡ���ɹ���" << endl;
	}
	else
	{
		cout << "�����������������룡" << endl;
		goto loopq;
	}
	return head;
}
void printAcademicData(Graduate_a *head)//���ѧ���о�������
{
	Graduate_a *p = head->pnext;
	if (head->pnext == NULL)
	{
		cerr << "������룺0x156456�������������ݣ�" << endl;
		cerr << "����ϵ����Ա����" << endl;
		system("pause");
		exit(0);
	}
	while (p != NULL)
	{
		cout << *p << endl;
		p = p->pnext;
	}
	return;
}
void modifyAcademicData()//�޸�ѧ���о���������
{
	Graduate_a *p, *q;
	p = seekAcademicData(Graduate::aHead);
	q = new Graduate_a;
	q->pnext = p->pnext;
	if (q == NULL)
	{
		cerr << "�������0x156112" << endl;
		cerr << "����ϵ����Ա�����" << endl;
		system("pause");
		exit(0);
	}
	cin >> *q;
	int i = 0;
loop:
	cout << "�Ƿ�ȷ���޸� �ǣ�1���� ��2����" << endl;
	cin >> i;
	if (i == 1)
	{
		*p = *q;
		cout << "�޸ĳɹ�" << endl;
	}
	else if (i == 2)
	{
		cout << "ȡ���ɹ���" << endl;
		delete q;
	}
	else
	{
		cerr << "�������� ���������룡" << endl;
		goto loop;
	}
	return;
}