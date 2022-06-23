#include"BusCard.h"
#include"BusCardSystem.h"
#include"Help.h"
#include"Passenger.h"
#include<sstream>
#include <iostream>
#include<stdlib.h>
#include<algorithm>
int main()
{
	Passenger* p = new Passenger();
	BusCard* b = new BusCard();
	while (true)
	{
		cout << ConsoleColor::Purple << "======公交卡充值管理系统==========" << endl;
		cout << ConsoleColor::Cyan << "\n[1] 登录  [2]公交刷卡  [4] 退出系统 " << endl;
		char select;
		cin >> select;
		if (select == '1') {
			string num1, num2;
			cout <<ConsoleColor::Rad<< "请输入账户：";
			cin >> num1;
			cout <<ConsoleColor::Rad<< "请输入密码：";
			cin >> num2;
			string dataPath = "data.txt";
			string data1 = "账号: " + num1;
			string data2 = "密码: " + num2;
			WriteFile(dataPath, data1, data2);//传出文件名，账号，密码
			if (judge()== 1)//登录成功；
			{
				system("pause");
				system("cls");
				while (true) {
					cout <<ConsoleColor::Green<< "======公交卡充值管理系统==========" << endl;
					cout << ConsoleColor::Cyan << "[1] 购买公交卡与充值  [2] 查询余额 [3] 用户信息 [4] 返回上一级 " << endl;
					char tem;
					cin >> tem;
					if (tem == '1') {//[1] 购买公交卡与充值 
						system("pause");
						system("cls");
						while (true) {
							cout <<ConsoleColor::Yellow<< "============购买买公交卡与充值===================" << endl;
							cout <<ConsoleColor::Cyan<< "[1].购买公交车卡  [2].充值  [3].返回上一级" << endl;
							char select1, select2;
							cin >> select1;
							if (select1 == '1') {//办卡
								cout << "需要支付100元:";
								cout << "\n[1].确认支付  [2].返回" << endl;
								cin >> select2;
								if (select2 == '1') {
									p->setjianmoney(100);
									p->getmoney();
									p->buyBusCards();
									cout << "支付成功！！！" << endl;
									cout << "请给你的卡起个名字：" << endl;
									string cardName;
									cin >> cardName;
									b->setName(cardName);
									cout << "起名字成功" << endl;
									system("pause");
									system("cls");
									break;
								}
								else {
									system("pause");
									system("cls");
									continue;
								}
							}
							if (select1 == '2') {//[2].充值
								if (p->haveBusCard == 0) {//判断是否办卡，
									//没有办卡
									cout << ConsoleColor::Purple << "您还没有办卡，请先去办卡在充值" << endl;
									system("pause");
									system("cls");
									break;
								}
								else {//已经办卡
									int cinmoney;
									cout << "请输入充值金额：" << endl;
									cin >> cinmoney;
									p->setjianmoney(cinmoney);//充值  对乘客的进行扣钱
									p->getmoney();
									b->addMoney(cinmoney);
									if (p->haveMoney >= 10)
									{
										cout << "充值成功！" << endl;
										system("pause");
										system("cls");
										break;

									}
									else {
										// 充值失败，钱包余额不足！;
										system("pause");
										system("cls");
										break;
									}

								}
							}
							if (select1 == '3') {//返回上一级
								system("pause");
								system("cls");
								break;
							}
							else {
								cout << "输入有误！请重新输入：" << endl;
								system("cls");
								continue;
							}
						}
					}
					if (tem == '2') {// [2] 查询余额 
						if (p->haveBusCard == 0) {
							cout << "你还没有获得公交卡" << endl;
							system("pause");
							system("cls");
						}
						else {
							cout << "公交卡的名字为：" << b->getName() << endl;
							cout << "公交卡余额：" << b->money << "元" << endl;
							system("pause");
							system("cls");
						}
					}
					if (tem == '3') {//用户信息
						cout << "==========用户信息================" << endl;
						cout << data1 << endl;//账号
						cout << data2 << endl;//密码
						cout << "钱包余额：" << p->haveMoney << "元" << endl;
						if (p->haveBusCard == 0) {//判断是否办过卡
							//没有办过
							cout <<ConsoleColor::Green<< "你还没有办过公交卡!" << endl;
						}
						else {
							//已办过
							cout <<ConsoleColor::Green<< "你已办过公交卡" << endl;
							cout << "公交卡的名字为："<<b->getName() << endl;
							cout << "余额为："<<b->money <<"元"<< endl;
							cout << "消费了:" << b->getExpend() <<"元"<< endl;
						}
						system("pause");
						system("cls");
					}
					if (tem == '4') {
						cout << "返回上一级" << endl;
						break;
					}
					else {
						//cout << "输入有误！请重新输入：" << endl;
						system("cls");
						continue;
					}
				}
				system("pause");
				system("cls");
			}
			else {
				cout << "请重新选择" << endl;
				continue;
			}
		}
		else if (select == '2') {//公交刷卡
	while (true) 
		{
			cout << "======模拟乘坐公交车==========" << endl;
			cout <<ConsoleColor::Black<< "上车需支付 5元" << endl;
			cout <<ConsoleColor::Rad<< "请输入支付金额：";
			int inmoney;
			cin >> inmoney;
			if (b->reduceMoney(inmoney)) {
				b->setExpend(inmoney);
				cout <<ConsoleColor::Purple<< "支付成功    祝你生活愉快！" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				cout <<ConsoleColor::Rad<< "支付失败！" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	continue;
	}
		else if (select == '4')
		{
			//保存本次的游戏数据
			
			if (b->getExpend() == 0) { break; }//判断是否为空，如果为空就不进行记录
			else {
				cout << "历史记录：" << endl;
				string dataPath = "data111.txt";
				string  data1;
				int data2;
				data1 = "名称：" + b->getName() + "\t花费：";
				data2 = b->getExpend();
				WriteFile(dataPath, data1, data2);
				Writeifile(dataPath);
				cout << "退出系统成功，希望下次再来" << endl;
				break;
			}
		}
		else{
		//cout << "输入有误！请重新输入：" << endl;
		system("cls");
			continue;
		}
	}
}

