#pragma once
#include"BusCard.h"
//�˿�
#include"Help.h"
class Passenger
{
public :
	double haveMoney = 2000;
	void  setjianmoney(int cinmoney);
	double getmoney();
	double haveBusCard=0;
	void buyBusCards();
};

