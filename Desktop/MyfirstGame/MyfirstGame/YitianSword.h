#pragma once
#include <iostream>
using namespace std;
#include "Weapon.h"
class YitianSword :public Weapon
{
public:
	//��ʼ��С������
	YitianSword();

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

