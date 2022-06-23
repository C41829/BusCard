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
	//文件流
	ofstream file(fileName);
	//写入数据
	file << data1;
	file << data2 << endl;
	file.close();
	//返回结果
	return true;
}
inline int judge() {
		fstream ifs;
		ifs.open("data.txt", ios::in);
		if (!ifs.is_open()) {
			cout << "文件打开失败";
		}
		string num;
		while (getline(ifs, num)) 
		{
			if (num == "账号: 123456密码: 123456")
			{
				cout << "登录成功"<<endl;
				return 1;
			}
			else {
				cout << "账号或密码错误" << endl;
				system("pause");
				system("cls");
				return 0;
			}
		}
	}
//枚举：定义控制台前景色
enum class ConsoleColor {
	Rad,
	Green,
	Blue,
	Black,
	white,
	Yellow,//黄色【红色+绿色】
	Cyan,//青色【蓝色+绿色】
	Purple//紫色【红色+蓝色】
};
inline ostream& operator <<(ostream& out, ConsoleColor color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (color) {
	case ConsoleColor::Rad: {
		//红色
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Green: {
		//绿色
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Black: {
		//黑色
		SetConsoleTextAttribute(handle, 0);
		break;
	}
	case ConsoleColor::white: {
		//白色(红+绿+蓝)
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Yellow: {
		//黄色（红+绿）
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Cyan: {
		//青色（蓝+绿）
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	}
	case ConsoleColor::Purple: {
		//紫色【红色+蓝】
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
	//文件流
	ofstream file(fileName, ios::app);
	//写入数据
	file << data1<<data2<< endl;
	file.close();
	//返回结果
	return true;
}
inline void Writeifile(string fileName) {
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！";
	}
	string num;
	while(getline(ifs,num))
	{
	cout <<num<<endl;
	}
	ifs.close();
	}
