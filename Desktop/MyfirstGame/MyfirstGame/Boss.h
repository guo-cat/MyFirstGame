//������
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "hero.h"
#include "FileManger.h"
#include <map>

class Hero;
class Boss
{
public:
	Boss(int id);					//��ʼ��������

	void FinghtHero(Hero *heroMan);    //���﹥��Ӣ��
public:
	int bossAtk;		   //���﹥����
	int bossDef;		   //���������
	int bossHp;			   //��������ֵ
	string bossName;	   //��������
	bool ifFrozen;		   //�Ƿ񱻱���

};