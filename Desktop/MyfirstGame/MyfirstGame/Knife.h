//С����
#pragma once
#include <iostream>
using namespace std;
#include "Weapon.h"
class Knife :public Weapon
{
public:
	//��ʼ��С������
	Knife();

	//��ȡ�����˺�
	virtual int getBaseAtk();

	//��ȡ����Ч�� ������>0ʱ�򴥷�����
	virtual int getWeaponCri();

	//��ȡ��ѪЧ�� ������0ʱ�򴥷���Ѫ
	virtual int getWeaponSuck();

	//��ȡ����Ч�� ������0��������Ч��
	virtual int getWeaponFrozen();

	//��������
	virtual bool isTrigger(int rate);
};
