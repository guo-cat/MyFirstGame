//怪物类
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
	Boss(int id);					//初始化怪物类

	void FinghtHero(Hero *heroMan);    //怪物攻击英雄
public:
	int bossAtk;		   //怪物攻击力
	int bossDef;		   //怪物防御力
	int bossHp;			   //怪物生命值
	string bossName;	   //怪物名字
	bool ifFrozen;		   //是否被冰冻

};