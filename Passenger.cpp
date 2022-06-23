#include "Passenger.h"

void Passenger::setjianmoney(int cinmoney)
{
			if (haveMoney >= 100) {
				haveMoney = haveMoney - cinmoney;//给公交卡充值
			}
			else {
				cout <<ConsoleColor::Rad<< "充值失败，钱包没钱了！" << endl;
				haveMoney = haveMoney;
			}
}
double Passenger::getmoney()
{
		return haveMoney;
}
void Passenger::buyBusCards()
{
	haveBusCard = 1;//为 1 买过卡了
}
