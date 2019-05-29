//������
#pragma once
#include <iostream>
using namespace std;
#include <string>
class Weapon
{
public:
	//��ȡ�����˺�
	virtual int getBaseAtk()=0;

	//��ȡ����Ч�� ������>0ʱ�򴥷�����
	virtual int getWeaponCri()=0;

	//��ȡ��ѪЧ�� ������0ʱ�򴥷���Ѫ
	virtual int getWeaponSuck()=0;

	//��ȡ����Ч�� ������0��������Ч��
	virtual int getWeaponFrozen()=0;

	//��������
	virtual bool isTrigger(int rate)=0;

public:
	string weaponName;    //��������
	int baseAtk;          //���������˺�
	int weaponCriPlus;    //��������ϵ��
	int weaponCriRate;	  //����������
	int weaponSuckPlus;   //������Ѫϵ��
	int weaponSuckRate;   //������Ѫ��
	int weaponFrozenRate; //����������
	
};