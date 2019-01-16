#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include"RecordA.h"
#include"FileManage.h"
#include"error.h"
using namespace std;

void addStudentData()//menuѡ��1��Ӧ����
{
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ¼��             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ¼��             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	while(1){
		Inputdata(choice, cin);
		if (choice == 1) {
			firstInputData(Graduate_a::aHead);
			saveStudentData(Graduate_a::aHead);
			break;
		}
		else if (choice == 2) {
			firstInputData(Graduate_e::eHead);
			saveStudentData(Graduate_e::eHead);
			break;
		}
		else if (choice == 3)
			return;
		else {
			cout << "�����������������"<<endl;
		}
	}
	cout << "¼��ɹ�" << endl;
}

void insertData() {	//menuѡ��2����
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	
	while(1) {
		Inputdata(choice, cin);
		if (choice == 1) {
			Graduate_a* tmp = new Graduate_a();
			cout << "����ѧ���о�����Ϣ" << endl;
			cin >> *tmp;
			tmp->pnext = Graduate_a::aHead->pnext;
			Graduate_a::aHead->pnext = tmp;
			saveStudentData(Graduate_a::aHead);
			break;
		}
		else if (choice == 2) {
			Graduate_e* tmp = new Graduate_e();
			cout << "���빤���о�����Ϣ" << endl;
			cin >> *tmp;
			tmp->pnext = Graduate_e::eHead->pnext;
			Graduate_e::eHead->pnext = tmp;
			saveStudentData(Graduate_e::eHead);
			break;
		}
		else if (choice == 3)
			return;
		else {
			cout << "�����������������" << endl;
		}
	}
	cout << "����ɹ�" << endl;
}

void delData() {//menuѡ��3����
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣɾ��             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣɾ��             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1) {
			delAcademicData(Graduate_a::aHead, Graduate_a::del_aHead);
			break;
		}
		else if (choice == 2) {
			delAcademicData(Graduate_e::eHead, Graduate_e::del_eHead);
			break;
		}
		else if (choice == 3)
			return;
		else {
			cout << "�����������������" << endl;
		}
	}
	cout << "ɾ���ɹ���" << endl;
}

void printData() {//menuѡ��4����
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ��ʾ             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ��ʾ             " << "*" << endl;
	cout << "*" << "                3.�����о�����Ϣ��ʾ             " << "*" << endl;
	cout << "*" << "                4.����                           " << "*" << endl;
	cout << "***************************************************" << endl;

	int choice;
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1)
		{
			cout << "ѧ���о�����Ϣ����" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "ѧ���о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "ѧ���о�����Ϣ������" << endl<<endl;
			break;
		}
		else if (choice == 2)
		{
			cout << "�����о�����Ϣ����" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "�����о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "�����о�����Ϣ������" << endl<<endl;
			break;
		}
		else if (choice == 3)
		{
			cout << "ѧ���о�����Ϣ����" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "ѧ���о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "ѧ���о�����Ϣ������" << endl;

			cout << "�����о�����Ϣ����" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "�����о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "�����о�����Ϣ������" << endl;
			break;
		}
		else if (choice == 4) {
			return;
		}
		else {
			cout << "�����������������" << endl;
		}
	}
}

void modifyData() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ�޸�             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ�޸�             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1)
		{
			Graduate_a* tmp = seekAcademicData(Graduate_a::aHead).first;
			cout << "��Ը�ѧ������Ϣ�����޸�!" << endl;
			cin >> *tmp;
			cout << "�޸ĳɹ�" << endl;
			break;
		}
		else if(choice==2)
		{
			Graduate_e* tmp = seekEngineerData(Graduate_e::eHead).first;
			cout << "��Ը�ѧ������Ϣ�����޸�!" << endl;
			cin >> *tmp;
			cout << "�޸ĳɹ�" << endl;
			break;
		}
		else if (choice == 3) {
			return;
		}
		else {
			cout << "�����������������" << endl;
		}
	}
}

void seekGraduateStudent() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1) {
			Graduate_a *p;
			p = seekAcademicData(Graduate_a::aHead).first;
			if (p)cout << *p;
			break;
		}
		else if (choice == 2) {
			Graduate_e *p;
			p = seekEngineerData(Graduate_e::eHead).first;
			if (p)cout << *p;
			break;
		}
		else if (choice == 3)
			return;
		else
			cout << "�������" << endl;
	}
		
}

void statisticalStudentData() {
	for (;;) {
		cout << "***************************************************" << endl;
		cout << "*" << "             ****ͳ��ϵͳ****                " << "*" << endl;
		cout << "*" << "                1.���ɼ��Ա�����             " << "*" << endl;
		cout << "*" << "                2.��ѧ�ŶԱ�����             " << "*" << endl;
		cout << "*" << "                3.�������Ա�����             " << "*" << endl;
		cout << "*" << "                4.������Ϣ�ſ�               " << "*" << endl;
		cout << "*" << "                5.����                           " << "*" << endl;
		cout << "***************************************************" << endl;
		int choice;
		Inputdata(choice, cin);
		switch (choice) {
		case 4:
			Graduate_a::statisticalData();
			Graduate_e::statisticalData();
			break;
		case 5:
			return;
		case 1:case 2:case 3: {
			Graduate_a::Bsort(choice);
			Graduate_e::Bsort(choice);
			saveStudentData(Graduate_a::aHead);
			saveStudentData(Graduate_e::eHead);
			cout << "�������......" << endl;
			cout << "ѧ���о�����Ϣ����" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "ѧ���о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "ѧ���о�����Ϣ������" << endl;

			cout << "�����о�����Ϣ����" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "�����о�����ϢΪ�գ�����¼��" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "�����о�����Ϣ������" << endl;
			break;
		}
			
		default:
			cout << "�������" << endl;
			continue;
		}
		break;
	}
}

void initSystem() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "            �ò�������ɾ������ѧ����Ϣ           " << "*" << endl;
	cout << "*" << "          ������ϵͳ���Ƿ���Ҫ���У�(y/n)        " << "*" << endl;
	cout << "***************************************************" << endl;

	char c;
	cin >> c;

	if (c =='y')
	{
		Graduate_a * tmp1 = new Graduate_a();
		Graduate_e * tmp2 = new Graduate_e();
		saveStudentData(tmp1);
		saveStudentData(tmp2);
		loadAcademicStudentData(Graduate_a::aHead);
		loadEngineerStudentData(Graduate_e::eHead);
		cout << "�ѳɹ�����ϵͳ" << endl;
	}
	else
		return;

}

void exitSystem() {
	/*
	cout << "���ļ�������Ϣ" << endl;
	Graduate_a* tmp = getAcademicStudentData(Graduate_a::aHead);
	cout << *(tmp->pnext) << endl;*/
	system("pause");
	exit(0);
};

void recycle() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.ѧ���о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                2.�����о�����Ϣ����             " << "*" << endl;
	cout << "*" << "                3.����                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	Inputdata(choice, cin);
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "�����������������" << endl;
		Inputdata(choice, cin);
	}
	Graduate_a* tmp = Graduate_a::aHead->pnext;
	if (choice == 1) {
		cout << "ѧ���о�������վ��Ϣ����" << endl;
		Graduate_a* tmp = Graduate_a::del_aHead->pnext;
		while (tmp)
		{
			cout << *tmp << endl;
			tmp = tmp->pnext;
		}
		cout << "��Ϣ������" << endl;
		cout << "����1���أ�����2�ָ�ĳ�����3���" << endl;
		Inputdata(choice, cin);
		switch (choice)
		{
		case 2:recycleData(Graduate_a::aHead, Graduate_a::del_aHead); break;
		//case 3:deletehead(Graduate_a::del_aHead->pnext); break;
		case 3:Graduate_a::del_aHead->pnext = NULL; break;
		default:
			break;
		}
	}
	else if (choice == 2) {
		cout << "�����о�������վ��Ϣ����" << endl;
		Graduate_e* tmp = Graduate_e::del_eHead->pnext;
		while (tmp)
		{
			cout << *tmp << endl;
			tmp = tmp->pnext;
		}
		cout << "��Ϣ������" << endl;
		cout << "����1���أ�����2�ָ�ĳ�����3���" << endl;
		Inputdata(choice, cin);
		switch (choice)
		{
		case 2:recycleData(Graduate_e::eHead, Graduate_e::del_eHead); break;
		case 3:deletehead(Graduate_e::del_eHead->pnext); break;
		default:
			break;
		}
	}
	else if (choice == 3)
		return;
	else
	{
		cout << "�������"<<endl;
	}
}

void menu()//�˵�����
{
	loadEngineerStudentData(Graduate_e::eHead);
	loadAcademicStudentData(Graduate_a::aHead);

	while (1) {
		int i;
		cout << "***************************************************" << endl;
		cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
		cout << "*" << "                1.�о�����Ϣ¼��*                " << "*" << endl;
		cout << "*" << "                2.�о�����Ϣ����                 " << "*" << endl;
		cout << "*" << "                3.�о�����Ϣɾ��                 " << "*" << endl;
		cout << "*" << "                4.�о�����Ϣ���                 " << "*" << endl;
		cout << "*" << "                5.�о�����Ϣ�޸�                 " << "*" << endl;
		cout << "*" << "                6.�о�����Ϣ����                 " << "*" << endl;
		cout << "*" << "                7.�о�����Ϣͳ��                 " << "*" << endl;
		cout << "*" << "                8.�˳�ϵͳ                       " << "*" << endl;
		cout << "*" << "                9.��ʼ����ϵͳ                   " << "*" << endl;
		cout << "*" << "                10.����վ                         " << "*" << endl;
		cout << "****************************************************" << endl;

		cout << "��ѡ��:" << endl;
		Inputdata(i, cin);
		switch (i) {
		case 1:
			addStudentData();//��Ϣ¼��
			system("pause");
			system("cls");
			break;
		case 2:
			insertData();//��Ϣ����
			system("pause");
			system("cls");
			break;
		case 3:
			delData();//��Ϣɾ��
			system("pause");
			system("cls");
			break;
		case 4:
			printData();//��Ϣ���
			system("pause");
			system("cls");
			break;
		case 5:
			modifyData();//��Ϣ�޸�
			system("pause");
			system("cls");
			break;
		case 6:
			seekGraduateStudent();//��Ϣ����
			system("pause");
			system("cls");
			break;
		case 7:
			statisticalStudentData();//��Ϣͳ��
			system("pause");
			system("cls");
			break;
		case 8:
			exitSystem();//ϵͳ�˳�����
			break;
		case 9:
			initSystem();//��ʼ��ϵͳ
			system("pause");
			system("cls");
			break;
		case 10:
			recycle();
			system("pause");
			system("cls");
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
	}
}

void welcome()//��ӭ����
{
	cout << "************************************" << endl;
	cout << "*****         ��ӭʹ��         *****" << endl << endl;
	cout << "****     �о����ɼ�����ϵͳ     ****" << endl << endl;;
	cout << "* ���ߣ���Ϣ��ѧ�빤��ѧԺ�ƿ�1705 *" << endl << endl;;
	cout << "****   ��Ʒ���ڣ�2018��1��15��  ****" << endl;
	cout << "************************************" << endl;
	//�������
	int i = 0;
	string user;
	string key;
	while (1) {
		cout << "�������û�����" << endl;
		cin >> user;
		cout << "��������" << endl;
		cin >> key;
		if (!(user == "admin" && key == "admin"))
		{
			i++;
			if (i >= 3)
			{
				cout << "���ѳ������������ϵͳ���Զ��˳���" << endl;
				system("pause");
				exit(0);
			}
			cout << "�˻�������������������������" << endl;
		}
		else
		{
			cout << "��ϲ��������ȷ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
