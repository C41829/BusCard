#include "Passenger.h"

void Passenger::setjianmoney(int cinmoney)
{
			if (haveMoney >= 100) {
				haveMoney = haveMoney - cinmoney;//����������ֵ
			}
			else {
				cout <<ConsoleColor::Rad<< "��ֵʧ�ܣ�Ǯ��ûǮ�ˣ�" << endl;
				haveMoney = haveMoney;
			}
}
double Passenger::getmoney()
{
		return haveMoney;
}
void Passenger::buyBusCards()
{
	haveBusCard = 1;//Ϊ 1 �������
}
