#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include"RecordA.h"
#include"FileManage.h"
#include"error.h"
using namespace std;

void addStudentData()//menu选项1对应函数
{
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息录入             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息录入             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
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
			cout << "输入错误，请重新输入"<<endl;
		}
	}
	cout << "录入成功" << endl;
}

void insertData() {	//menu选项2函数
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息插入             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息插入             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	
	while(1) {
		Inputdata(choice, cin);
		if (choice == 1) {
			Graduate_a* tmp = new Graduate_a();
			cout << "输入学术研究生信息" << endl;
			cin >> *tmp;
			tmp->pnext = Graduate_a::aHead->pnext;
			Graduate_a::aHead->pnext = tmp;
			saveStudentData(Graduate_a::aHead);
			break;
		}
		else if (choice == 2) {
			Graduate_e* tmp = new Graduate_e();
			cout << "输入工程研究生信息" << endl;
			cin >> *tmp;
			tmp->pnext = Graduate_e::eHead->pnext;
			Graduate_e::eHead->pnext = tmp;
			saveStudentData(Graduate_e::eHead);
			break;
		}
		else if (choice == 3)
			return;
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}
	cout << "插入成功" << endl;
}

void delData() {//menu选项3函数
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息删除             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息删除             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	}
	cout << "删除成功！" << endl;
}

void printData() {//menu选项4函数
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息显示             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息显示             " << "*" << endl;
	cout << "*" << "                3.所有研究生信息显示             " << "*" << endl;
	cout << "*" << "                4.返回                           " << "*" << endl;
	cout << "***************************************************" << endl;

	int choice;
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1)
		{
			cout << "学术研究生信息如下" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "学术研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "学术研究生信息输出完毕" << endl<<endl;
			break;
		}
		else if (choice == 2)
		{
			cout << "工程研究生信息如下" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "工程研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "工程研究生信息输出完毕" << endl<<endl;
			break;
		}
		else if (choice == 3)
		{
			cout << "学术研究生信息如下" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "学术研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "学术研究生信息输出完毕" << endl;

			cout << "工程研究生信息如下" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "工程研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "工程研究生信息输出完毕" << endl;
			break;
		}
		else if (choice == 4) {
			return;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}
}

void modifyData() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息修改             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息修改             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	
	while (1) {
		Inputdata(choice, cin);
		if (choice == 1)
		{
			Graduate_a* tmp = seekAcademicData(Graduate_a::aHead).first;
			cout << "请对该学生的信息进行修改!" << endl;
			cin >> *tmp;
			cout << "修改成功" << endl;
			break;
		}
		else if(choice==2)
		{
			Graduate_e* tmp = seekEngineerData(Graduate_e::eHead).first;
			cout << "请对该学生的信息进行修改!" << endl;
			cin >> *tmp;
			cout << "修改成功" << endl;
			break;
		}
		else if (choice == 3) {
			return;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}
}

void seekGraduateStudent() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息查找             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息查找             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
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
			cout << "输入错误" << endl;
	}
		
}

void statisticalStudentData() {
	for (;;) {
		cout << "***************************************************" << endl;
		cout << "*" << "             ****统计系统****                " << "*" << endl;
		cout << "*" << "                1.按成绩对表排序             " << "*" << endl;
		cout << "*" << "                2.按学号对表排序             " << "*" << endl;
		cout << "*" << "                3.按姓名对表排序             " << "*" << endl;
		cout << "*" << "                4.总体信息概况               " << "*" << endl;
		cout << "*" << "                5.返回                           " << "*" << endl;
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
			cout << "排序完毕......" << endl;
			cout << "学术研究生信息如下" << endl;
			Graduate_a* tmp = Graduate_a::aHead->pnext;
			if (!tmp)
				cout << "学术研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp)
				{
					cout << *tmp << endl;
					tmp = tmp->pnext;
				}
			}
			cout << "学术研究生信息输出完毕" << endl;

			cout << "工程研究生信息如下" << endl;
			Graduate_e* tmp2 = Graduate_e::eHead->pnext;
			if (!tmp2)
				cout << "工程研究生信息为空，请先录入" << endl;
			else
			{
				while (tmp2)
				{
					cout << *tmp2 << endl;
					tmp2 = tmp2->pnext;
				}
			}
			cout << "工程研究生信息输出完毕" << endl;
			break;
		}
			
		default:
			cout << "输入错误" << endl;
			continue;
		}
		break;
	}
}

void initSystem() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "            该操作将会删除所有学生信息           " << "*" << endl;
	cout << "*" << "          并重置系统，是否仍要进行？(y/n)        " << "*" << endl;
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
		cout << "已成功重置系统" << endl;
	}
	else
		return;

}

void exitSystem() {
	/*
	cout << "从文件读入信息" << endl;
	Graduate_a* tmp = getAcademicStudentData(Graduate_a::aHead);
	cout << *(tmp->pnext) << endl;*/
	system("pause");
	exit(0);
};

void recycle() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息回收             " << "*" << endl;
	cout << "*" << "                2.工程研究生信息回收             " << "*" << endl;
	cout << "*" << "                3.返回                           " << "*" << endl;
	cout << "***************************************************" << endl;
	int choice;
	Inputdata(choice, cin);
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "输入错误，请重新输入" << endl;
		Inputdata(choice, cin);
	}
	Graduate_a* tmp = Graduate_a::aHead->pnext;
	if (choice == 1) {
		cout << "学术研究生回收站信息如下" << endl;
		Graduate_a* tmp = Graduate_a::del_aHead->pnext;
		while (tmp)
		{
			cout << *tmp << endl;
			tmp = tmp->pnext;
		}
		cout << "信息输出完毕" << endl;
		cout << "输入1返回，输入2恢复某项，输入3清空" << endl;
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
		cout << "工程研究生回收站信息如下" << endl;
		Graduate_e* tmp = Graduate_e::del_eHead->pnext;
		while (tmp)
		{
			cout << *tmp << endl;
			tmp = tmp->pnext;
		}
		cout << "信息输出完毕" << endl;
		cout << "输入1返回，输入2恢复某项，输入3清空" << endl;
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
		cout << "输入错误"<<endl;
	}
}

void menu()//菜单界面
{
	loadEngineerStudentData(Graduate_e::eHead);
	loadAcademicStudentData(Graduate_a::aHead);

	while (1) {
		int i;
		cout << "***************************************************" << endl;
		cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
		cout << "*" << "                1.研究生信息录入*                " << "*" << endl;
		cout << "*" << "                2.研究生信息插入                 " << "*" << endl;
		cout << "*" << "                3.研究生信息删除                 " << "*" << endl;
		cout << "*" << "                4.研究生信息输出                 " << "*" << endl;
		cout << "*" << "                5.研究生信息修改                 " << "*" << endl;
		cout << "*" << "                6.研究生信息查找                 " << "*" << endl;
		cout << "*" << "                7.研究生信息统计                 " << "*" << endl;
		cout << "*" << "                8.退出系统                       " << "*" << endl;
		cout << "*" << "                9.初始化该系统                   " << "*" << endl;
		cout << "*" << "                10.回收站                         " << "*" << endl;
		cout << "****************************************************" << endl;

		cout << "请选择:" << endl;
		Inputdata(i, cin);
		switch (i) {
		case 1:
			addStudentData();//信息录入
			system("pause");
			system("cls");
			break;
		case 2:
			insertData();//信息插入
			system("pause");
			system("cls");
			break;
		case 3:
			delData();//信息删除
			system("pause");
			system("cls");
			break;
		case 4:
			printData();//信息输出
			system("pause");
			system("cls");
			break;
		case 5:
			modifyData();//信息修改
			system("pause");
			system("cls");
			break;
		case 6:
			seekGraduateStudent();//信息查找
			system("pause");
			system("cls");
			break;
		case 7:
			statisticalStudentData();//信息统计
			system("pause");
			system("cls");
			break;
		case 8:
			exitSystem();//系统退出函数
			break;
		case 9:
			initSystem();//初始化系统
			system("pause");
			system("cls");
			break;
		case 10:
			recycle();
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}
}

void welcome()//欢迎界面
{
	cout << "************************************" << endl;
	cout << "*****         欢迎使用         *****" << endl << endl;
	cout << "****     研究生成绩管理系统     ****" << endl << endl;;
	cout << "* 作者：信息科学与工程学院计科1705 *" << endl << endl;;
	cout << "****   出品日期：2018年1月15日  ****" << endl;
	cout << "************************************" << endl;
	//密码操作
	int i = 0;
	string user;
	string key;
	while (1) {
		cout << "请输入用户名：" << endl;
		cin >> user;
		cout << "请输入口令：" << endl;
		cin >> key;
		if (!(user == "admin" && key == "admin"))
		{
			i++;
			if (i >= 3)
			{
				cout << "您已超过输入次数，系统将自动退出！" << endl;
				system("pause");
				exit(0);
			}
			cout << "账户或密码输入有误！请重新输入" << endl;
		}
		else
		{
			cout << "恭喜！输入正确！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
