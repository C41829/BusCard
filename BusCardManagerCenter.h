#pragma once
#include"BusCard.h"
class BusCardManagerCenter
{
public :
	double centerMoney;
private:
	BusCardManagerCenter();
public :
	BusCard setBusCard(double money);
	bool moneyToCard(double money, BusCard busCard) {}
};

