#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include"Student.h"
using namespace std;

void addStudentData()//menu选项1对应函数
{
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息录入                " << "*" << endl;
	cout << "*" << "                2.工程研究生信息录入                 " << "*" << endl;
	cout << "****************************************************" << endl;
	int choice;
	cin >> choice;
	/*if (choice == 1)
		Graduate_a::aHead->saveAcademicStudentData();
	else
		Graduate_e::eHead->saveEngineerStudentData();*/
}


void insertData() {	//menu选项2函数
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息录入                " << "*" << endl;
	cout << "*" << "                2.工程研究生信息录入                 " << "*" << endl;
	cout << "****************************************************" << endl;
	int choice;
	cin >> choice;
	//if (choice == 1)
		//aHead->saveAcademicStudentData();
	//else
		//eHead->saveEngineerStudentData();
}


void delData() {//menu选项3函数
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息删除                " << "*" << endl;
	cout << "*" << "                2.工程研究生信息删除                 " << "*" << endl;
	cout << "****************************************************" << endl;
	int choice;
	cin >> choice;
	//暂时没写if else
}


void printData() {

}


void modifyData() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息修改                " << "*" << endl;
	cout << "*" << "                2.工程研究生信息修改                 " << "*" << endl;
	cout << "****************************************************" << endl;
	int choice;
	cin >> choice;
	//暂时没写if else
}
void seekGraduateStudent() {
	cout << "***************************************************" << endl;
	cout << "*" << "             ****研究生管理系统****              " << "*" << endl;
	cout << "*" << "                1.学术研究生信息查找               " << "*" << endl;
	cout << "*" << "                2.工程研究生信息查找                 " << "*" << endl;
	cout << "****************************************************" << endl;
	int choice;
	cin >> choice;
	//暂时没写if else
}
void statisticalStudentData() {

}
void initSystem() {
	system("cls");
}
void exitSystem() {
	system("pause");
	exit(0);
};

void menu()//菜单界面
{
	int i = 0;
	for (;;) {
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
		cout << "****************************************************" << endl;

		cout << "请选择:" << endl;

		cin >> i;
		switch (i)
		{
		case 1:
			addStudentData();//信息录入
			cout << "录入成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			insertData();//信息插入
			cout << "插入成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			delData();//信息删除
			cout << "删除成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			printData();//信息输出
			cout << "输出成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			modifyData();//信息修改
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			seekGraduateStudent();//信息查找
			cout << "查找成功！" << endl;
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
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	return;
}


void welcome()//欢迎界面
{
	cout << "************************************" << endl;
	cout << "*****         欢迎使用         *****" << endl << endl;
	cout << "****     研究生成绩管理系统     ****" << endl << endl;;
	cout << "*  作者：信息科学与工程学院计科1705   *" << endl << endl;;
	cout << "****   出品日期：2018年1月14日  ****" << endl;
	cout << "************************************" << endl;
	//密码操作
	int i = 0;
	string user;
	string key;
loop:
	cout << "请输入用户名：" << endl;
	cin >> user;
	cout << "请输入口令：" << endl;
	cin >> key;
	if (!(user == "xin" && key == "xin"))
	{
		i++;
		if (i >= 3)
		{
			cout << "您已超过输入次数，系统将自动退出！" << endl;
			system("pause");
			exit(0);
		}
		cout << "账户或密码输入有误！请重新输入" << endl;
		goto loop;
	}
	else
	{
		cout << "恭喜！输入正确！" << endl;
		system("pause");
		system("cls");
	}
	return;
}
