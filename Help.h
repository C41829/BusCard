#pragma once
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<sstream>

#include"BusCard.h"
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<vector>
using std::stringstream;
using namespace std;
inline bool WriteFile(string fileName, string data1,string data2)
{
	//�ļ���
	ofstream file(fileName);
	//д������
	file << data1;
	file << data2 << endl;
	file.close();
	//���ؽ��
	return true;
}
inline int judge() {
		fstream ifs;
		ifs.open("data.txt", ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ���ʧ��";
		}
		string num;
		while (getline(ifs, num)) 
		{
			if (num == "�˺�: 123456����: 123456")
			{
				cout << "��¼�ɹ�"<<endl;
				return 1;
			}
			else {
				cout << "�˺Ż��������" << endl;
				system("pause");
				system("cls");
				return 0;
			}
		}
	}
//ö�٣��������̨ǰ��ɫ
enum class ConsoleColor {
	Rad,
	Green,
	Blue,
	Black,
	white,
	Yellow,//��ɫ����ɫ+��ɫ��
	Cyan,//��ɫ����ɫ+��ɫ��
	Purple//��ɫ����ɫ+��ɫ��
};
inline ostream& operator <<(ostream& out, ConsoleColor color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color) {
	case ConsoleColor::Rad: {
		//��ɫ
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Green: {
		//��ɫ
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Black: {
		//��ɫ
		SetConsoleTextAttribute(handle, 0);
		break;
	}
	case ConsoleColor::white: {
		//��ɫ(��+��+��)
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Yellow: {
		//��ɫ����+�̣�
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Cyan: {
		//��ɫ����+�̣�
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Purple: {
		//��ɫ����ɫ+����
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	}

	default:
		break;
	}
	return out;
}
inline bool WriteFile(string fileName, string data1,int  data2)
{
	//�ļ���
	ofstream file(fileName, ios::app);
	//д������
	file << data1<<data2<< endl;
	file.close();
	//���ؽ��
	return true;
}
inline void Writeifile(string fileName) {
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�";
	}
	string num;
	while(getline(ifs,num))
	{
	cout <<num<<endl;
	}
	ifs.close();
	}
