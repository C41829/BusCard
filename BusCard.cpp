#include "BusCard.h"

bool BusCard::reduceMoney(int inmoney)
{
	if (inmoney > 0) {
		if (money > inmoney) {
			money = money - inmoney;
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}
void BusCard::addMoney(int money)
	{
		this->money = this->money + money;
	}

void BusCard::setName(string name)
{
	this->name = name;
}

string BusCard::getName()
{
	return name;
}

void BusCard::setExpend(int inmoney)
{
	num += inmoney;
}

int BusCard::getExpend()
{
	return num;
}