//Ӣ����Ĵ���
#pragma once
#include <iostream>
using namespace std;
#include "Weapon.h"
#include "FileManger.h"
#include <map>
#include "Boss.h"
class Boss;
class Hero
{
public:
	//��ʼ��
	Hero(int id);

	//����ģʽ ѡ�񹥻��ĸ�Boss
	void Attack(Boss *boss);

	//ѡ�������
	void HaveWeapon(Weapon *weapon);

public:
	int heroAtk;				//Ӣ�۹�����
	int heroHp;					//Ӣ������ֵ
	int heroDef;				//Ӣ�۷�����
	string heroName;		    //Ӣ������
	string heroInfo;			//Ӣ�ۻ�����Ϣ
	Weapon *weapon;				//��ӵ�е�����
};