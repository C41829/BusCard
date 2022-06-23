#pragma once
#include<iostream>
#include<string>
using namespace std;
class BusCard
{
public:
	string name;
	double money = 0;
	double cardPrice;
	int num =0;
	bool  reduceMoney(int inmoney);
	void addMoney(int money);
	void setName(string name);
	string getName();
	void setExpend(int inmoney); 
	int getExpend();
};

