#pragma once

#include<string>

#include<iostream>
using namespace std;
template<class T>
void Inputdata(T &i, istream &in) {
	in >> i;
	while (in.fail()) {
		cerr << "�����������������" << endl;
		in.clear();
		while (in.get() != '\n') {
			continue;
		}
		in >> i;
	}
}


